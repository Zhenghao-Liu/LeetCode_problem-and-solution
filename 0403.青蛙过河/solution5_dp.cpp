typedef long long ll;
const int MAXN=2e3;
int dp[MAXN][MAXN];
class Solution {
public:
    bool canCross(vector<int>& stones) {
        memset(dp,0,sizeof(dp));
        int sz=stones.size();
        if (stones[1]!=1) {
            return false;
        }
        dp[1][1]=1;
        vector<ll> vec{-1,0,1};
        for (int i=2;i<sz;i++) {
            for (int j=0;j<i;j++) {
                int dis=stones[i]-stones[j];
                for (ll k:vec) {
                    ll step=dis+k;
                    if (step>0 && step<sz && dp[j][step]==1) {
                        dp[i][dis]=1;
                        if (dp[i][dis]==1) {
                            break;
                        }
                    }
                }
            }
        }
        for (int i=1;i<sz;i++) {
            if (dp[sz-1][i]==1) {
                return true;
            }
        }
        return false;
    }
};