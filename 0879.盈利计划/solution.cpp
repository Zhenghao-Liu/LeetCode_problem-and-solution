// dp[i][j][k]，考虑到第i个计划（从1开始），用了j个人（从0开始），利润至少为k的方案数
typedef long long ll;
ll mod=1e9+7;
const int MAXN=100,MAXG=100,MAXP=100;
ll dp[MAXG+1][MAXN+1][MAXP+1];
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        int sz=group.size();
        for (int i=1;i<=sz;i++) {
            int gro=group.at(i-1);
            int pro=profit.at(i-1);
            for (int j=0;j<=n;j++) {
                for (int k=0;k<=minProfit;k++) {
                    dp[i][j][k]+=dp[i-1][j][k];
                    dp[i][j][k]%=mod;
                    if (j>=gro) {
                        dp[i][j][k]+=dp[i-1][j-gro][max(0,k-pro)];
                        dp[i][j][k]%=mod;
                    }
                }
            }
        }
        ll ans=0;
        for (int j=0;j<=n;j++) {
            ans+=dp[sz][j][minProfit];
            ans%=mod;
        }
        return ans;
    }
};