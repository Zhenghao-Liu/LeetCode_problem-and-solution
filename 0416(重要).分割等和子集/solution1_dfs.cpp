//设所有数求和为sum，那只要分出两个集合和为sum/2的即可
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int &i:nums)
            sum+=i;
        if (sum%2==1)
            return false;
        sort(nums.begin(),nums.end());
        int nums_size=nums.size();
        return dfs(nums,sum/2,sum/2,nums_size-1);
    }
    bool dfs(vector<int> &nums,int left,int right,int index)
    {
        if (left==0 || right==0)
            return true;
        if (left<0 || right<0)
            return false;
        return dfs(nums,left-nums.at(index),right,index-1) || dfs(nums,left,right-nums.at(index),index-1);        
    }
};
