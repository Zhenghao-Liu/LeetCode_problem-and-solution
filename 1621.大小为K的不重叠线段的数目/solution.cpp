/*
 * dp[i][j][0]表示0~i的点构造j条线段，且第j条线段的右端点不是i的方案数
   dp[i][j][1]表示0~i的点构造j条线段，且第j条线段的右端点是i的方案数
 * 即dp[i][j][0]转移时第j条线段无法延伸
   即dp[i][j][1]转移时第j条线段是可以延长的
 ** 转移方程1: dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1]
   因为第j条线段右端点不是i，即表明点0~点i-1就已经构建了j条线段
 ** 转移方程2: dp[i][j][1]
   1. 若第j条线段长度为1，则表明点0~点i-1就已经构建了j-1条线段
      所以dp[i-1][j-1][0]+dp[i-1][j-1][1]
   2. 若第j条线段长度大于1，即表明第j条线段长度至少是2，则删除第j条线段在点i-1到点i的部分，
      在点0~点i-1仍然满足有j条线段，且第j条线段的右端点一定是点i-1
      所以dp[i-1][j][1]
 ** 最终答案就是dp[n-1][j][0]+dp[n-1][j][1]
 ** 初始化dp[i][0][0]=1
 */
typedef long long ll;
const int MAXN=1000;
int dp[MAXN][MAXN][2];
int mod=1e9+7;
class Solution {
public:
    int numberOfSets(int n, int k) {
        memset(dp,0,sizeof(dp));
        for (int i=0;i<n;++i)
            dp[i][0][0]=1;
        for (int i=1;i<n;++i)
            for (int j=1;j<=k;++j)
            {
                dp[i][j][0]=((ll)dp[i-1][j][0]+dp[i-1][j][1])%mod;
                dp[i][j][1]=((ll)dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j][1])%mod;
            }
        return ((ll)dp[n-1][k][0]+dp[n-1][k][1])%mod;
    }
};
