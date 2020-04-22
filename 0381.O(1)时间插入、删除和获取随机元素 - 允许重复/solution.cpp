class RandomizedCollection {
    unordered_map<int,unordered_set<int>> pos_index;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        pos_index.clear();
        v.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool judge=(pos_index.count(val)==0);
        pos_index[val].insert(v.size());
        v.push_back(val);
        return judge;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (pos_index.count(val)==0)
            return false;
        int old_pos_index=*(pos_index.at(val).begin());
        pos_index.at(val).erase(old_pos_index);
        pos_index.at(v.back()).insert(old_pos_index);
        pos_index.at(v.back()).erase(v.size()-1);
        if (pos_index.at(val).empty())
            pos_index.erase(val);
        v.at(old_pos_index)=v.back();
        v.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v.at(rand()%v.size()+0);
    }
};
