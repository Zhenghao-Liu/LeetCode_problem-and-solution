const int MAXN=12;
int dp[MAXN][1<<MAXN];
const int INF=0x3f3f3f3f;
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        memset(dp,0x3f,sizeof(dp));
        int sz=graph.size();
        int ALL=(1<<sz)-1;
        for (int i=0;i<sz;i++) {
            dp[i][1<<i]=0;
        }
        for (int j=1;j<=ALL;j++) {
            for (int i=0;i<sz;i++) {
                if (dp[i][j]==INF) {
                    continue;
                }
                for (int nxt:graph.at(i)) {
                    dp[nxt][(1<<nxt)|j]=min(dp[nxt][(1<<nxt)|j],dp[i][j]+1);
                }
            }
            for (int i=0;i<sz;i++) {
                if (dp[i][j]==INF) {
                    continue;
                }
                for (int nxt:graph.at(i)) {
                    dp[nxt][(1<<nxt)|j]=min(dp[nxt][(1<<nxt)|j],dp[i][j]+1);
                }
            }
        }
        int ans=INF;
        for (int i=0;i<sz;i++) {
            ans=min(ans,dp[i][ALL]);
        }
        return ans;
    }
};