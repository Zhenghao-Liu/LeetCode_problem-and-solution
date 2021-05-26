// dp[i][j] 第i步到达位置j
typedef long long ll;
ll mod=1e9+7;
const int MAXN=500+1;
ll dp[MAXN][MAXN];
vector<int> dir{-1,0,1};
class Solution {
public:
    int numWays(int steps, int arrLen) {
        if (arrLen==1 || steps==1) {
            return 1;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        int mxLen=min(steps,arrLen-1);
        for (int i=1;i<=steps;i++) {
            for (int j=0;j<=mxLen;j++) {
                for (int x:dir) {
                    int xx=j+x;
                    if (xx>=0 && xx<=mxLen) {
                        dp[i][j]+=dp[i-1][xx];
                        dp[i][j]%=mod;
                    }
                }
            }
        }
        return dp[steps][0];
    }
};