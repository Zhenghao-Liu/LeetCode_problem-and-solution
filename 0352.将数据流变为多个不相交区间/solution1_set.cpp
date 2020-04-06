class SummaryRanges {
private:
    set<int> num;
    vector<vector<int>> cache;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        num.clear();
        cache.clear();
    }
    
    void addNum(int val) {
        num.insert(val);
        cache.clear();
    }
    
    vector<vector<int>> getIntervals() {
        if (cache.size()!=0 || num.size()==0)
            return cache;
        int start=*(num.begin());
        int end=start;
        for (auto &i:num)
            if (i-1==end || i==end)
                end=i;
            else
            {
                cache.push_back({start,end});
                start=end=i;
            }
        cache.push_back({start,*(num.rbegin())});
        return cache;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
