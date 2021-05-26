/*
 * 拓扑排序+图上dp
 * 显然从入度为0的节点开始遍历是最优的，所以采取拓扑排序方式
 * 如果有环，拓扑排序是遍历不完所有节点的，所以只需要判断遍历节点数是否所有节点，即可有无环
 * dp[i][j]表示从入度为0的节点遍历到当前节点i，颜色为j的最多可能出现次数
 * 没有必要每条线路都维护一个int[26]，因为只考虑最大值，所以只用每个点去维护int[26]
   然后不同线路去对比每个颜色下的最大值即可
 */
const int MAXN=1e5+1;
const int MAXC=26;
int dp[MAXN][MAXC];
int ind[MAXN];
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        memset(dp,0,sizeof(dp));
        memset(ind,0,sizeof(int)*n);
        vector<vector<int>> edge(n);
        for (vector<int> &i:edges) {
            edge.at(i.at(0)).push_back(i.at(1));
            ind[i.at(1)]++;
        }
        queue<int> que;
        for (int i=0;i<n;i++) {
            if (ind[i]==0) {
                que.push(i);
            }
        }
        int cho=0;
        while (!que.empty()) {
            int cur=que.front();
            que.pop();
            cho++;
            dp[cur][colors.at(cur)-'a']++;
            for (int nxt:edge.at(cur)) {
                ind[nxt]--;
                if (ind[nxt]==0) {
                    que.push(nxt);
                }
                for (int c=0;c<MAXC;c++) {
                    dp[nxt][c]=max(dp[nxt][c],dp[cur][c]);
                }
            }
        }
        if (cho!=n) {
            return -1;
        }
        int ans=-1;
        for (int i=0;i<n;i++) {
            for (int c=0;c<MAXC;c++) {
                ans=max(ans,dp[i][c]);
            }
        }
        return ans;
    }
};