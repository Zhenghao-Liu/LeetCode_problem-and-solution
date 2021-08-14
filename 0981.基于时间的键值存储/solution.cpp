class TimeMap {
    unordered_map<string,map<int,string>> ump;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        ump.clear();
    }
    
    void set(string key, string value, int timestamp) {
        ump[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        auto p=ump.find(key);
        if (p==ump.end()) {
            return "";
        }
        auto &mp=p->second;
        auto pp=mp.lower_bound(timestamp);
        if (pp!=mp.end() && pp->first<=timestamp) {
            return pp->second;
        }
        if (pp!=mp.begin()) {
            pp--;
            return pp->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */