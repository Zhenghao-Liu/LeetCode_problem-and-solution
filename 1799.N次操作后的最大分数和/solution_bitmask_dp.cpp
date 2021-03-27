// __builtin_popcount
const int INF=0xc0c0c0c0;
const int MAXN=1<<(7*2);
int dp[MAXN];
const int MAXI=14;
int g[MAXI][MAXI];
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int sz=nums.size();
        for (int i=0;i<sz;i++) {
            for (int j=i+1;j<sz;j++) {
                int t=__gcd(nums.at(i),nums.at(j));
                g[i][j]=g[j][i]=t;
            }
        }
        memset(dp,0xc0,sizeof(dp));
        dp[0]=0;
        int ALL=(1<<sz)-1;
        for (int i=0;i<=ALL;i++) {
            if (dp[i]==INF) {
                continue;
            }
            int cnt=__builtin_popcount(i)/2+1;
            for (int j=0;j<sz;j++) {
                if ((i&(1<<j))!=0) {
                    continue;
                }
                for (int k=j+1;k<sz;k++) {
                    if ((i&(1<<k))!=0) {
                        continue;
                    }
                    int nxt=i|(1<<j)|(1<<k);
                    dp[nxt]=max(dp[nxt],dp[i]+cnt*g[j][k]);
                }
            }
        }
        return dp[ALL];
    }
};