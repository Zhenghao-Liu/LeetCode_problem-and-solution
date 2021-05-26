const int INF=0x3f3f3f3f;
const int MAXM=100,MAXN=20;
int dp[MAXM][MAXN][MAXM+1];
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,0x3f,sizeof(dp));
        if (houses.at(0)!=0) {
            int col=houses.at(0)-1;
            dp[0][col][1]=0;
        } else {
            for (int j=0;j<n;j++) {
                dp[0][j][1]=cost.at(0).at(j);
            }
        }
        for (int i=1;i<m;i++) {
            if (houses.at(i)!=0) {
                int col=houses.at(i)-1;
                for (int j=0;j<n;j++) {
                    for (int k=1;k<=i;k++) {
                        if (dp[i-1][j][k]!=INF) {
                            if (j==col) {
                                dp[i][col][k]=min(dp[i][col][k],dp[i-1][j][k]);
                            } else {
                                dp[i][col][k+1]=min(dp[i][col][k+1],dp[i-1][j][k]);
                            }
                        }
                    }
                }
            } else {
                for (int col=0;col<n;col++) {
                    for (int j=0;j<n;j++) {
                        for (int k=1;k<=i;k++) {
                            if (dp[i-1][j][k]!=INF) {
                                if (j==col) {
                                    dp[i][col][k]=min(dp[i][col][k],dp[i-1][j][k]+cost.at(i).at(col));
                                } else {
                                    dp[i][col][k+1]=min(dp[i][col][k+1],dp[i-1][j][k]+cost.at(i).at(col));
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans=INF;
        for (int j=0;j<n;j++) {
            ans=min(ans,dp[m-1][j][target]);
        }
        return ans==INF ? -1 : ans;
    }
};