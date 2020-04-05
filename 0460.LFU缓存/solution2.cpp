/*
* 重载set的排序<，使得使用频率最少且最远使用的放在前面
* 通过set来确定删除的键值
*/
struct Node{
    int key,value;
    //cnt表示频率，time表示时间戳
    int cnt,time;
    Node(int _key,int _value,int _cnt,int _time):key(_key),value(_value),cnt(_cnt),time(_time){}
    //函数后面一定要加const
    bool operator<(const Node &A) const
    {
        if (cnt<A.cnt)
            return true;
        else if (cnt==A.cnt)
            return time<A.time;
        return false;
    }
};
class LFUCache {
private:
    //time表示时间戳
    int max_size,time;
    //哈希表存{key,对应节点}
    unordered_map<int,Node> dict;
    set<Node> helper_set;
public:
    LFUCache(int capacity) {
        max_size=capacity;
        time=0;
        dict.clear();
        helper_set.clear();
    }
    
    int get(int key) {
        unordered_map<int,Node>::iterator p_dict=dict.find(key);
        if (p_dict==dict.end())
            return -1;
        Node mapping_node=p_dict->second;
        //不要在set内修改，应该拿出来修改再放回去
        helper_set.erase(mapping_node);
        ++time;
        mapping_node.time=time;
        mapping_node.cnt+=1;
        p_dict->second=mapping_node;
        helper_set.insert(mapping_node);
        return mapping_node.value;
    }
    
    void put(int key, int value) {
        if (max_size==0)
            return;
        unordered_map<int,Node>::iterator p_dict=dict.find(key);
        if (p_dict!=dict.end())
        {
            Node mapping_node=p_dict->second;
            helper_set.erase(mapping_node);
            ++time;
            mapping_node.time=time;
            mapping_node.cnt+=1;
            mapping_node.value=value;
            p_dict->second=mapping_node;
            helper_set.insert(mapping_node);
            return;
        }
        if (helper_set.size()==max_size)
        {
            dict.erase(helper_set.begin()->key);
            helper_set.erase(helper_set.begin());
        }
        ++time;
        Node new_node(key,value,1,time);
        dict.insert({key,new_node});
        helper_set.insert(new_node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
