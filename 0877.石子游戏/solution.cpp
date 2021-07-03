const int MAXN=500;
int dp[MAXN][MAXN];
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        memset(dp,0xc0,sizeof(dp));
        int sz=piles.size();
        for (int i=0;i<sz;i++) {
            dp[i][i]=piles.at(i);
        }
        return dfs(piles,0,sz-1)>0;
    }
    int dfs(vector<int> &piles,int st,int ed) {
        if (dp[st][ed]!=0xc0c0c0c0) {
            return dp[st][ed];
        }
        dp[st][ed]=max(
            piles.at(st)-dfs(piles,st+1,ed),
            piles.at(ed)-dfs(piles,st,ed-1)
        );
        return dp[st][ed];
    }
};