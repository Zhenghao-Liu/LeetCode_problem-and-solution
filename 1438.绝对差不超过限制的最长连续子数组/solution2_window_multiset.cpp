class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int nums_size=nums.size();
        //first存值
        //second存对应值在nums的位置
        multiset<pair<int,int>> helper;
        int ans=0;
        for (int l=0,r=0;l<nums_size;++l)
        {
            while (!helper.empty() && helper.begin()->second<l)
                helper.erase(helper.begin());
            while (!helper.empty() && helper.rbegin()->second<l)
                helper.erase((++helper.rbegin()).base());
            int current_min=helper.empty() ? INT_MAX : helper.begin()->first;
            int current_max=helper.empty() ? INT_MIN : helper.rbegin()->first;
            while (r<nums_size && max(nums.at(r),current_max)-min(nums.at(r),current_min)<=limit)
            {
                helper.insert({nums.at(r),r});
                current_min=helper.begin()->first;
                current_max=helper.rbegin()->first;
                ++r;
            }
            if (r-l>ans)
                ans=r-l;
        }
        return ans;
    }
};
