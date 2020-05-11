class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int &i:nums)
            sum+=i;
        if (sum%2==1)
            return false;
        int target=sum/2;
        int nums_size=nums.size();
        //dp[i][j]表示nums中[0]~[i]可否选出子元素构成和为j的情况
        vector<vector<bool>> dp(nums_size,vector<bool>(target+1,false));
        //j=0即和为0情况，那只要不取行了，所以一定可以
        for (int i=0;i<nums_size;++i)
            dp.at(i).at(0)=true;
        //对于第一行单独讨论，因为只有一个数字，j=nums[0]时即取nums[0]就可以了，其他除了0的情况都不可能
        if (nums.at(0)<=target)
            dp.at(0).at(nums.at(0))=true;
        for (int i=1;i<nums_size;++i)
            for (int j=1;j<=target;++j)
            {
                //对于第nums[i]个数，要想实现和为j有两种可能
                //不取nums[i]，那结果就是在[0]~[i-1]能否实现和为j，即dp[i-1][j]
                //取nums[i]，那结果就是在[0]~[i-1]能否实现和为j-nums[i]的情况，即dp[i-1][j-nums[i]]
                //但要注意越界的可能
                if (j-nums.at(i)>=0)
                    dp.at(i).at(j)=dp.at(i-1).at(j) || dp.at(i-1).at(j-nums.at(i));
                else
                    dp.at(i).at(j)=dp.at(i-1).at(j);
            }
        return dp.at(nums_size-1).at(target);
    }
};
