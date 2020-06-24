/*
* 数组最大和不超过1000，即sum<=1000，那最小值就是所有数都带符号即min(sum)=-1000，即-1000<=sum<=1000，
* 那么这里一共有1000-(-1000)+1=2001个数，所以只需要开2001大小的数组即可，
* 为什么是+1000呢，因为要想不越界就必须-1000+x>=0 && 1000+x<2001则推出来是1000
* dp[i][j+1000]表示处理到nums[i]时和为j的组合有多少个
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S>1000)
            return 0;
        int nums_size=nums.size();
        vector<vector<int>> dp(nums_size,vector<int>(2001,0));
        dp.at(0).at(nums.at(0)+1000)+=1;
        dp.at(0).at(-nums.at(0)+1000)+=1;
        for (int i=1;i<nums_size;++i)
        {
            for (int j=0;j<2001;++j)
            {
                if (dp.at(i-1).at(j)>0)
                {
                    dp.at(i).at(j+nums.at(i))+=dp.at(i-1).at(j);
                    dp.at(i).at(j-nums.at(i))+=dp.at(i-1).at(j);
                }
            }
        }
        return dp.at(nums_size-1).at(S+1000);
    }
};
