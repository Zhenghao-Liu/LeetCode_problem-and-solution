//状压，将出现的数字所对应的位设为1，没出现则为0
const int MAXN=31251;
class MyHashSet {
    unsigned int myshash[MAXN];
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        memset(myshash,0,sizeof(myshash));
    }
    
    void add(int key) {
        int i=key/32;
        int j=key%32;
        myshash[i]|=1<<j;
    }
    
    void remove(int key) {
        int i=key/32;
        int j=key%32;
        myshash[i]&=~(1<<j);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int i=key/32;
        int j=key%32;
        return (myshash[i]&(1<<j))!=0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
