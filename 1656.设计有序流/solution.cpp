class OrderedStream {
    int size;
    vector<string> vec;
    int idx;
public:
    OrderedStream(int n) {
        size=n+1;
        vec=vector<string>(n+1,"");
        idx=1;
    }
    
    vector<string> insert(int id, string value) {
        vec.at(id)=value;
        vector<string> ans;
        while (idx<size && !vec.at(idx).empty())
        {
            ans.push_back(vec.at(idx));
            ++idx;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
