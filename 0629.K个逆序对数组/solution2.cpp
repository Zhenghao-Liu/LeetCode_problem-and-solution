/*
* 转移方程dp[i][j]=dp[i-1][j]+dp[i-1][j-1]+···+dp[i-1][j-(i-1)]
* 可以按照一行一行从左到右方式填表
  即for(int i=2;i<=n;++i) for(int j=1;j<=k;++j)
* 可以观察得到dp[i][j]依赖于左上，且对于dp[i][j+1]，他其中包含了很多dp[i][j]的重复运算
* 所以优化转移方程：将dp[i][j]中的j替换成j-1
  dp[i][j-1]=dp[i-1][j-1]+dp[i-1][j-2]+···+dp[i-1][j-i]
  并将上式代入dp[i][j]
  即dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-i]
*/
const int maxn=1e3+1;
const int maxk=1e3+1;
int dp[maxn][maxk];
class Solution {
    int mod=1e9+7;
public:
    int kInversePairs(int n, int k) {
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n;++i)
            dp[i][0]=1;
        for (int i=2;i<=n;++i)
            for (int j=1;j<=k;++j)
            {
                long long a=dp[i-1][j];
                long long b=dp[i][j-1];
                long long c=j-i>=0 ? dp[i-1][j-i] : 0;
                dp[i][j]=(a+b-c+mod)%mod;
            }
        return dp[n][k];
    }
};
