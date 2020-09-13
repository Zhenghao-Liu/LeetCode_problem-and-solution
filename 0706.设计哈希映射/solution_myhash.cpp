/*
* 整体思路同705.设计哈希集合
* 但是映射多一个value，所以采用pair存储
* 哈希映射处理index=key%key_base
* 同样发生哈希冲突时，用链表存储
*/
typedef pair<int,int> pii;
class MyHashMap {
    const int key_base=769;
    vector<list<pii>> myhash;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        myhash=vector<list<pii>>(key_base);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index=key%key_base;
        auto start=myhash.at(index).begin();
        auto end=myhash.at(index).end();
        for (auto i=start;i!=end;++i)
            if ((*i).first==key)
            {
                (*i).second=value;
                return;
            }
        myhash.at(index).push_back({key,value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index=key%key_base;
        auto start=myhash.at(index).begin();
        auto end=myhash.at(index).end();
        for (auto i=start;i!=end;++i)
            if ((*i).first==key)
            {
                return (*i).second;
            }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index=key%key_base;
        auto start=myhash.at(index).begin();
        auto end=myhash.at(index).end();
        for (auto i=start;i!=end;++i)
            if ((*i).first==key)
            {
                myhash.at(index).erase(i);
                return;
            }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
