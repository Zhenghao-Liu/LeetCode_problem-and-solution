//key存右边界，value存左边界，左闭右闭
//二分查找即可
class MyCalendar {
    map<int,int> ans;
public:
    MyCalendar() {
        ans.clear();
    }
    
    bool book(int start, int end) {
        --end;
        auto p=ans.lower_bound(start);
        if (p!=ans.end() && p->second<=end)
            return false;
        ans[end]=start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
