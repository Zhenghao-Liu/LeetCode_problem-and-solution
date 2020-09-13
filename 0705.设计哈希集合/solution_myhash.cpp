/*
* 单独链接法：对于相同的散列值，我们将它们放到一个桶中，每个桶是相互独立的
* 映射函数index=key%key_base
  key_base设为769(别问为啥，就是选一个特别的大小适中的质数)
* 若出现哈希映射冲突，则用链表存储同一个映射值的所有元素
  以便于删除和插入
*/
class MyHashSet {
    const int key_base=769;
    vector<list<int>> myhash;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        myhash=vector<list<int>>(key_base);
    }
    
    void add(int key) {
        int index=key%key_base;
        auto start=myhash.at(index).begin();
        auto end=myhash.at(index).end();
        for (auto i=start;i!=end;++i)
            if (*i==key)
                return;
        myhash.at(index).push_back(key);
    }
    
    void remove(int key) {
        int index=key%key_base;
        auto start=myhash.at(index).begin();
        auto end=myhash.at(index).end();
        for (auto i=start;i!=end;++i)
            if (*i==key)
            {
                myhash.at(index).erase(i);
                return;
            }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index=key%key_base;
        auto start=myhash.at(index).begin();
        auto end=myhash.at(index).end();
        for (auto i=start;i!=end;++i)
            if (*i==key)
                return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
