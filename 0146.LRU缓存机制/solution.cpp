/*
* 太懒了直接用了两个库类
* 可以用双向哈希链表进行优化(java中是LinkedHashMap)
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
        //当key值已经存在时
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
