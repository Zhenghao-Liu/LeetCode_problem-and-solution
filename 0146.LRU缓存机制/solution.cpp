/*
* 太懒了直接用了两个库类
* 可以用双向哈希链表进行优化(java中是LinkedHashMap)
*
* LRU(Least Recently Used):该算法的思路是，发生缺页中断时，选择未使用时间最长的页面置换出去。
* 可利用一个特殊的栈来保存当前使用的各个页面的页面号。
* 每当进程访问某页面时，便将该页面的页面号从栈中移出，将它压入栈顶。
* 因此，栈顶始终是最新被访问页面的编号，而栈底则是最近最久未使用页面的页面号
* 当栈满时，还要新加入元素时，则栈底出栈，即最久未使用的退出。
* 将新元素也要对应的压入栈顶
* 采用了deque来实现该特殊的栈
*/
class LRUCache {
private:
    unordered_map<int,int> answer_map;
    deque<int> use_times;
    int maxsize;
public:
    LRUCache(int capacity) {
        maxsize=capacity;
    }
    //读取数据，没有返回-1
    int get(int key) {
        if (answer_map.find(key)==answer_map.end())
            return -1;
        else
        {
            use_times.erase(find(use_times.begin(),use_times.end(),key));
            use_times.push_back(key);
            return answer_map.at(key);
        }
    }
    //写入数据
    void put(int key, int value) {
        //当key值已经存在时，注意可能key值对应的value刚好为-1的情况
        if (get(key)!=-1 || answer_map.find(key)!=answer_map.end())
        {
            answer_map.at(key)=value;
            return;
        }
        //未满时
        if (use_times.size()!=maxsize)
        {
            use_times.push_back(key);
            answer_map.insert({key,value});
        }
        //满了的情况
        else
        {
            int delete_key=use_times.front();
            use_times.pop_front();
            answer_map.erase(delete_key);
            answer_map.insert({key,value});
            use_times.push_back(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
