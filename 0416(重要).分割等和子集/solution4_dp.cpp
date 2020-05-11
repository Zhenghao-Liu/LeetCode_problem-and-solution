//既然二维dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i]]
//即只与上一行有关可以压缩成一维
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
        //压缩成一维
        vector<bool> dp(target+1,false);
        dp.at(0)=true;
        for (int i=1;i<nums_size;++i)
        {
            /**
            * 要保证j-nums[i]>=0不越界
            * 且j最大就是取到target
            * 所以nums[i]<=j<=target
            * 但是为什么要从后往前不是从前往后
            * eg 前一行[ ··· false ··· false]
                 这一行[ ··· true  ··· 要求]
                 我们按从左往右填
                 因为压缩成一维动态方程dp[j]=dp[j] || dp.at(j-nums[i])
                 由于从左往右填dp.at(j-nums[i])可能已经改值，造成错误
                 所以从后往前填
            */
            for (int j=target;j>=nums.at(i);--j)
                dp.at(j)=dp.at(j) || dp.at(j-nums.at(i));
            //剪枝
            if (dp.at(target))
                return true;
        }
        return dp.at(target);
    }
};
