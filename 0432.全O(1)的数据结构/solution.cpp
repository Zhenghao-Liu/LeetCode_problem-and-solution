//哈希表key存string，value存迭代器 list<pair<>> first存权值，second用集合存该权值下的所有string 然后迭代器疯狂操作，注意边界和是否要删除链表节点，或者单纯的移除集集合的一个string等一些小问题
class AllOne {
    unordered_map<string,list<pair<int,unordered_set<string>>>::iterator> dict;
    //按first升序
    list<pair<int,unordered_set<string>>> count;
public:
    /** Initialize your data structure here. */
    AllOne() {
        dict.clear();
        count.clear();
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (dict.find(key)==dict.end())
        {
            if (!count.empty() && count.front().first==1)
                (*(count.begin())).second.insert(key);
            else
                count.insert(count.begin(),{1,{key}});
            dict[key]=count.begin();
        }
        else
        {
            list<pair<int,unordered_set<string>>>::iterator p=dict.at(key);
            int new_value=(*p).first+1;
            ++p;
            list<pair<int,unordered_set<string>>>::iterator p_next=p;
            --p;
            (*p).second.erase((*p).second.find(key));
            if ((*p).second.empty())
                count.erase(p);
            if (p_next==count.end())
            {
                count.push_back({new_value,{key}});
                --p_next;
                dict.at(key)=p_next;
            }
            else
            {
                if (new_value==(*p_next).first)
                {
                    (*p_next).second.insert(key);
                    dict.at(key)=p_next;
                }
                else
                {
                    count.insert(p_next,{new_value,{key}});
                    --p_next;
                    dict.at(key)=p_next;
                }
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (dict.find(key)==dict.end())
            return;
        else
        {
            list<pair<int,unordered_set<string>>>::iterator p=dict.at(key);
            if ((*p).first==1)
            {
                dict.erase(dict.find(key));
                (*p).second.erase((*p).second.find(key));
                if ((*p).second.empty())
                    count.erase(p);
                return;
            }
            int new_value=(*p).first-1;
            if (p==count.begin())
            {
                (*p).second.erase((*p).second.find(key));
                if ((*p).second.empty())
                    count.erase(p);
                count.insert(count.begin(),{new_value,{key}});
                dict.at(key)=count.begin();
                return;
            }
            --p;
            list<pair<int,unordered_set<string>>>::iterator p_pre=p;
            ++p;
            (*p).second.erase((*p).second.find(key));
            if ((*p).second.empty())
                count.erase(p);
            if (new_value==(*p_pre).first)
            {
                (*p_pre).second.insert(key);
                dict.at(key)=p_pre;
            }
            else
            {
                ++p_pre;
                count.insert(p_pre,{new_value,{key}});
                --p_pre;
                dict.at(key)=p_pre;
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (count.empty())
            return "";
        return *(count.back().second.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (count.empty())
            return "";
        return *(count.front().second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
