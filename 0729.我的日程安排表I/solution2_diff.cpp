//key表示时间，表示后面的都被占用
//差分数组
class MyCalendar {
    map<int,int> ans;
public:
    MyCalendar() {
        ans.clear();
    }
    
    bool book(int start, int end) {
        ++ans[start];
        --ans[end];
        int cnt=0;
        for (auto & [k,v]:ans)
        {
            cnt+=v;
            if (cnt==2)
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
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
