class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int nums_size=nums.size();
        //first存值
        //second存对应值在nums的位置
        //记录滑窗的最小值
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_num;
        //记录滑窗的最大值
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> max_num;
        int ans=0;
        for (int l=0,r=0;l<nums_size;++l)
        {
            while (!min_num.empty() && min_num.top().second<l)
                min_num.pop();
            while (!max_num.empty() && max_num.top().second<l)
                max_num.pop();
            int current_min=min_num.empty() ? INT_MAX : min_num.top().first;
            int current_max=max_num.empty() ? INT_MIN : max_num.top().first;
            while (r<nums_size && max(nums.at(r),current_max)-min(nums.at(r),current_min)<=limit)
            {
                min_num.push({nums.at(r),r});
                max_num.push({nums.at(r),r});
                current_min=min_num.top().first;
                current_max=max_num.top().first;
                ++r;
            }
            if (r-l>ans)
                ans=r-l;
        }
        return ans;
    }
};
