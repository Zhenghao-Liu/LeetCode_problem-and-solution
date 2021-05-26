/*
 * dp[i][j]表示共有i根棍子，看得到j根
 * dp[i][i]表示有多少根就看得到多少根，所以一定是升序，也就只有1种可能
   即dp[i][i]=1
 * dp[i][j]可以看成是 共有i根棍子，我考虑的是插入最小的1根
     * 如果这根最小的棍子放在最前面，它一定会被看到，即dp[i-1][j-1]
       只有1种插法也就是最前面
     * 如果这根最小的棍子不是放在最前面，那么它一定不会被看到，即dp[i-1][j]
       一共有i-1种插法（一共有i-1根棍子，且不能放在最前面），所以是(i-1)*dp[i-1][j]
 * dp[i][j]=dp[i-1][j-1]+(i-1)*dp[i-1][j]      
 */
typedef long long ll;
ll mod=1e9+7;
const int MAXN=1e3+1;
ll dp[MAXN][MAXN];
class Solution {
public:
    int rearrangeSticks(int n, int k) {
        if (n==k) {
            return 1;
        }
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=k;j++) {
                if (i==j) {
                    dp[i][j]=1;
                    continue;
                }
                dp[i][j]+=dp[i-1][j-1];
                dp[i][j]%=mod;
                dp[i][j]+=dp[i-1][j]*(i-1)%mod;
                dp[i][j]%=mod;
            }
        }
        return dp[n][k];
    }
};