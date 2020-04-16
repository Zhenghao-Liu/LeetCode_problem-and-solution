/*
* 对于递归来说一般都是超时的，因为会重复计算，所以反过来dp
* dp[i][j]表示left=i，right=j的即猜(i,j)区间的数字最少要花多少钱
* 因此dp[left][right]只有left<=right情况下才有意义
* 当left==right时，即只有一个数字即不用猜只用0钱（vector初始化就是0）
* 转移方程i属于(left,right),dp[left][right]=min(ans,i+max(dp[left][i-1],dp[i+1][right]))
  当i=left或right时因为可能会造成边界溢出即[i][j]出现i>j情况所以单独讨论
* 注意填充顺序
  即对于[left,i-1]来说必然是在[left,right]的左边
  即对于[i+1,right]来说必然是在[left,right]的下边
  而dp的前提就是要先建立好前面的条件才能推出后面的结果，因此我们在处理[left][right]时一定要先填好它的左方和下方
*/
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for (int right=2;right<=n;++right)
            for (int left=right-1;left>=1;--left)
            {
                int ans=INT_MAX;
                for (int i=left+1;i<right;++i)
                    ans=min(ans,i+max(dp.at(left).at(i-1),dp.at(i+1).at(right)));
                ans=min(ans,left+dp.at(left+1).at(right));
                ans=min(ans,right+dp.at(left).at(right-1));
                dp.at(left).at(right)=ans;
            }
        return dp.at(1).at(n);
    }
};
