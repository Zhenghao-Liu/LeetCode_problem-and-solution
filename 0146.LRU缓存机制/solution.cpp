class LRUCache {
    //first为密匙
    //second为数据值
    //头部则最近使用
    list<pair<int,int>> times;
    //key为密匙
    //value为对应在times中位置
    unordered_map<int,list<pair<int,int>>::iterator> dict;
    int max_size;
public:
    LRUCache(int capacity) {
        max_size=capacity;
    }
    
    int get(int key) {
        if (dict.find(key)==dict.end())
            return -1;
        else
        {
            list<pair<int,int>>::iterator p=dict.at(key);
            pair<int,int> data=*p;
            times.erase(p);
            times.push_front(data);
            dict.at(key)=times.begin();
            return data.second;
        }
    }
    
    void put(int key, int value) {
        //key值已经存在
        if (dict.find(key)!=dict.end())
        {
            list<pair<int,int>>::iterator p=dict.at(key);
            pair<int,int> data=*p;
            data.second=value;
            times.erase(p);
            times.push_front(data);
            dict.at(key)=times.begin();
        }
        //未超过最大容量时
        else if (dict.size()!=max_size)
        {
            times.push_front({key,value});
            dict.insert({key,times.begin()});
        }
        //当前缓存已满
        else
        {
            pair<int,int> delete_data=times.back();
            times.pop_back();
            dict.erase(delete_data.first);
            //偷懒
            this->put(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
