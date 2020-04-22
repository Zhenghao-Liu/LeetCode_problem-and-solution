/*
* 用vector来存储元素
* 那随机访问就直接用随机数索引访问即可
* 增加也是直接在后面加复杂度也是O(1)
* 那删除怎么办呢，o(1)的方法就是直接去尾，但尾部不一定是我们要删除的元素
* 我们可以将要删除的元素和尾部的元素交换，但是我们要怎么知道要删除元素的位置呢
* 就需要insert时通过哈希表存入对应元素的位置，这样就能解决删除O(1)
*/
class RandomizedSet {
private:
    unordered_map<int,int> pos_index;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        pos_index.clear();
        v.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (pos_index.count(val)!=0)
            return false;
        pos_index[val]=v.size();
        v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (pos_index.count(val)==0)
            return false;
        int old_pos_index=pos_index.at(val);
        v.at(old_pos_index)=v.back();
        pos_index.at(v.back())=old_pos_index;
        v.pop_back();
        pos_index.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v.at(rand()%v.size()+0);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
