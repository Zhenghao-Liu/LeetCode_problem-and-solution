//首先要按照[i][0]升序排序
//dp[i]表示排序后以第intervals[i]为尾的区间，最大无重叠区间有多少个
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int intervals_size=intervals.size();
        if (intervals_size==0)
            return 0;
        vector<int> dp(intervals_size,1);
        int max_nooverlap=1;
        for (int i=1;i<intervals_size;++i)
        {
            int cur_max=0;
            for (int j=i-1;j>=0;--j)
                if (intervals[j][1]<=intervals[i][0])
                    if (dp[j]>cur_max)
                        cur_max=dp[j];
            dp[i]=cur_max+1;
            if (dp[i]>max_nooverlap)
                max_nooverlap=dp[i];
        }
        return intervals_size-max_nooverlap;
    }
};
