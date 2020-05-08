/*
* dp[i][k]表示对于stones[i]石头能否从上一个石头j跳跃k个单位到石头i
* 求k的最大可能：假设每一次都跳k+1个单位，那对应数组最大的能跳的k是size-1
  eg：[0 1 3 6] 0->1跳1 1->3跳2 3->6跳3 对于size=4的数组k的最大可能是size-1=3
  即对于一个数组stone k应该是满足1<=k<=size-1
* 要想石头j通过跳跃k个单位到达石头i
  那么说明到达石头j的'k'只有3种情况：
  1. 'k'=k+1通过跳 减1 个单位到石头i
  2. 'k'=k  通过跳 原本 个单位到石头i
  3. 'k'=k-1通过跳 加1 个单位到石头i
* 所以状态转移方程dp[i][k]=dp[j][k+1] || dp[j][k] || dp[j][k-1]
  注意越界的可能性(.at()居然tle了)
*/
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int stones_size=stones.size();
        vector<vector<bool>> dp(stones_size,vector<bool>(stones_size,false));
        dp[0][0]=true;
        for (int i=1;i<stones_size;++i)
            for (int j=0;j<i;++j)
            {
                int k=stones[i]-stones[j];
                /**
                * 记得k的取值范围 1<=k<=size-1
                * 因为j-i且[j]最大可能性就是[i]-1所以k>=1一定满足
                * 但是k<=size-1不一定满足，所以要特判
                */
                /**
                * 优化1：特判然后continue
                * 优化2：既然stones是有序数组那么stones[i]-stones[j]也是有序的，可以二分然后确定j的起始点
                * 优化3：j=i-1; ;--j;然后破范围直接break就好了
                */
                if (k>stones_size-1)
                    continue;
                dp[i][k]=dp[j][k-1] || dp[j][k];
                if (k+1<stones_size)
                    dp[i][k]=dp[i][k] || dp[j][k+1];
                if (i==stones_size-1 && dp[i][k])
                    return true;
            }
        return false;
    }
};
