//dict存{key,value},use_times存使用的频率，而recently_use则按照最近使用来存，结合使用频率和最近使用来更新缓存
class LFUCache {
private:
    unordered_map<int,int> dict;
    int max_size;
    deque<int> recently_use;
    unordered_map<int,int> use_times;
public:
    LFUCache(int capacity) {
        max_size=capacity;
    }
    
    int get(int key) {
        if (dict.find(key)==dict.end())
            return -1;
        else
        {
            recently_use.erase(find(recently_use.begin(),recently_use.end(),key));
            recently_use.push_back(key);
            ++use_times[key];
            return dict.at(key);
        }
    }
    
    void put(int key, int value) {
        if (max_size==0)
            return;
        if (dict.find(key)!=dict.end())
        {
            dict.at(key)=value;
            recently_use.erase(find(recently_use.begin(),recently_use.end(),key));
            recently_use.push_back(key);
            ++use_times.at(key);
            return;
        }
        if (recently_use.size()==max_size)
        {
            unordered_set<int> may_delete_key;
            int least_value=INT_MAX;
            for (auto &i:use_times)
                if (i.second<=least_value)
                {
                    if (i.second<least_value)
                    {
                        may_delete_key.clear();
                        least_value=i.second;
                    }
                    may_delete_key.insert(i.first);
                }
            for (deque<int>::iterator i=recently_use.begin();i!=recently_use.end();++i)
                if (may_delete_key.find(*i)!=may_delete_key.end())
                {
                    dict.erase(dict.find(*i));
                    use_times.erase(use_times.find(*i));
                    recently_use.erase(i);
                    break;
                }
        }
        recently_use.push_back(key);
        dict.insert({key,value});
        ++use_times[key];
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
