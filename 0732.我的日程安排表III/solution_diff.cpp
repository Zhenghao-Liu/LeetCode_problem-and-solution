class MyCalendarThree {
    map<int,int> helper;
public:
    MyCalendarThree() {
        helper.clear();
    }
    
    int book(int start, int end) {
        ++helper[start];
        --helper[end];
        int cnt=0;
        int ans=0;
        for (auto &[k,v]:helper)
        {
            cnt+=v;
            ans=max(ans,cnt);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
