// dp[i][j] 表示时间i，到达目的地j的最小花费
const int MAXT=1e3+1;
const int MAXN=1e3;
int dp[MAXT][MAXN];
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        memset(dp,0x3f,sizeof(dp));
        int sz=passingFees.size();
        vector<vector<pii>> edge(sz);
        for (vector<int> &i:edges) {
            int a=i.at(0),b=i.at(1),t=i.at(2);
            edge.at(a).push_back({b,t});
            edge.at(b).push_back({a,t});
        }
        dp[0][0]=passingFees.at(0);
        for (int t=1;t<=maxTime;t++) {
            for (int p=0;p<sz;p++) {
                for (auto [from,cos]:edge.at(p)) {
                    if (t>=cos && dp[t-cos][from]!=INF) {
                        dp[t][p]=min(dp[t][p],dp[t-cos][from]+passingFees.at(p));
                    }
                }
            }
        }
        int ans=INF;
        for (int t=1;t<=maxTime;t++) {
            ans=min(ans,dp[t][sz-1]);
        }
        return ans==INF ? -1 : ans;
    }
};