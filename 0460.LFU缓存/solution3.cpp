/*
* 哈希表查找O(1)，链表删除增加O(1)
* 我们用freq来限定链表，且最近使用的放在头端，即删除时从频率最小的尾部开始删除
*/
struct Node{
    int key,value,freq;
    Node(int _key,int _value,int _freq):key(_key),value(_value),freq(_freq){}
};
class LFUCache {
private:
    //[频率freq]对应着双向链表，即频率为freq的键值
    unordered_map<int,list<Node>> freq_table;
    //[key]对应着对应节点的地址
    unordered_map< int,list<Node>::iterator > key_table;
    //min_freq存当前最低频率
    int min_freq,max_size;
public:
    LFUCache(int capacity) {
        min_freq=0;
        max_size=capacity;
        freq_table.clear();
        key_table.clear();
    }
    
    int get(int key) {
        unordered_map< int,list<Node>::iterator >::iterator p_key_table=key_table.find(key);
        if (p_key_table==key_table.end())
            return -1;
        list<Node>::iterator p_node=p_key_table->second;
        int value=p_node->value;
        int freq=p_node->freq;
        freq_table.at(freq).erase(p_node);
        if (freq_table.at(freq).size()==0)
        {
            freq_table.erase(freq);
            if (min_freq==freq)
                ++min_freq;
        }
        ++freq;
        freq_table[freq].push_front(Node(key,value,freq));
        p_key_table->second=freq_table.at(freq).begin();
        return value;
    }
    
    void put(int key, int value) {
        if (max_size==0)
            return;
        unordered_map< int,list<Node>::iterator >::iterator p_key_table=key_table.find(key);
        if (p_key_table!=key_table.end())
        {
            list<Node>::iterator p_node=p_key_table->second;
            int freq=p_node->freq;
            freq_table.at(freq).erase(p_node);
            if (freq_table.at(freq).size()==0)
            {
                freq_table.erase(freq);
                if (min_freq==freq)
                    ++min_freq;
            }
            ++freq;
            freq_table[freq].push_front(Node(key,value,freq));
            p_key_table->second=freq_table.at(freq).begin();
            return;
        }
        if (key_table.size()==max_size)
        {
            int delete_key=freq_table.at(min_freq).back().key;
            key_table.erase(delete_key);
            freq_table.at(min_freq).pop_back();
            if (freq_table.at(min_freq).size()==0)
                freq_table.erase(min_freq);
        }
        min_freq=1;
        freq_table[1].push_front(Node(key,value,1));
        key_table.insert({key,freq_table.at(1).begin()});
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
