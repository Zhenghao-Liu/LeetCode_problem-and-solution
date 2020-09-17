//key存右边界，value存左边界，左闭右闭
class RangeModule {
    map<int,int> ans;
public:
    RangeModule() {
        ans.clear();
    }
    
    void addRange(int left, int right) {
        --right;
        for (auto i=ans.lower_bound(left-1);i!=ans.end() && i->second<=right+1;)
        {
            auto nxt=next(i,1);
            left=min(left,i->second);
            right=max(right,i->first);
            ans.erase(i);
            i=nxt;
        }
        ans[right]=left;
    }
    
    bool queryRange(int left, int right) {
        --right;
        auto p=ans.lower_bound(right);
        if (p==ans.end())
            return false;
        return (p->second)<=left;
    }
    
    void removeRange(int left, int right) {
        --right;
        int delete_left=INT_MAX;
        int delete_right=INT_MIN;
        for (auto i=ans.lower_bound(left);i!=ans.end() && i->second<=right;)
        {
            auto nxt=next(i,1);
            delete_left=min(delete_left,i->second);
            delete_right=max(delete_right,i->first);
            ans.erase(i);
            i=nxt;
        }
        if (delete_left<left)
            ans[left-1]=delete_left;
        if (delete_right>right)
            ans[delete_right]=right+1;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
