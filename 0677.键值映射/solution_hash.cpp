class MapSum {
    unordered_map<string,int> dict;
public:
    /** Initialize your data structure here. */
    MapSum() {
        dict.clear();
    }
    
    void insert(string key, int val) {
        dict[key]=val;
    }
    
    int sum(string prefix) {
        string s;
        int s_size;
        int prefix_size=prefix.size();
        int ans=0;
        for (auto &i:dict)
        {
            s=i.first;
            s_size=s.size();
            if (prefix_size>s_size)
                continue;
            int j;
            for (j=0;j<prefix_size;++j)
                if (s.at(j)!=prefix.at(j))
                    break;
            if (j==prefix_size)
                ans+=i.second;
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
