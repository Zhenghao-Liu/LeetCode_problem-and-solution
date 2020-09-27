//key表示时间，表示往后的时间都被占用的任务数
class MyCalendarTwo {
    map<int,int> ans;
public:
    MyCalendarTwo() {
        ans.clear();
    }
    
    bool book(int start, int end) {
        ++ans[start];
        --ans[end];
        int cnt=0;
        for (auto &[k,v]:ans)
        {
            cnt+=v;
            if (cnt==3)
            {
                --ans[start];
                ++ans[end];
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
