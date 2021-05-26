const int MAXN=12;
int sum[1<<MAXN];
int dp[MAXN][1<<MAXN];
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        memset(dp,0x3f,sizeof(dp));
        int sz=jobs.size();
        int ALL=(1<<sz)-1;
        sum[0]=0;
        dp[0][0]=0;
        for (int i=1;i<=ALL;i++) {
            int fir=32-__builtin_clz(i)-1;
            sum[i]=sum[i^(1<<fir)]+jobs.at(fir);
            dp[0][i]=sum[i];
        }
        for (int i=1;i<k;i++) {
            dp[i][0]=0;
            for (int j=1;j<=ALL;j++) {
                int subset=j;
                do
                {
                    if (subset==0) {
                        break;
                    }
                    int cur=sum[subset];
                    int pre=dp[i-1][j^subset];
                    dp[i][j]=min(dp[i][j],max(cur,pre));
                    subset=(subset-1)&j;
                }while(subset!=j);
            }
        }
        return dp[k-1][ALL];
    }
};