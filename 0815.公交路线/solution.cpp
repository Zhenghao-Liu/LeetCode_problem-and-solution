const int MAXN=1e6;
int vis[MAXN];
const int MAXL=500;
int busVis[MAXL];
const int INF=0x3f3f3f3f;
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source==target) {
            return 0;
        }
        int sz=routes.size();
        unordered_map<int,vector<int>> ump;
        for (int i=0;i<sz;i++) {
            for (int j:routes.at(i)) {
                ump[j].push_back(i);
            }
        }
        memset(vis,0x3f,sizeof(vis));
        memset(busVis,0,sizeof(busVis));
        vis[source]=0;
        queue<int> que;
        que.push(source);
        while (!que.empty()) {
            int cur=que.front();
            que.pop();
            for (int bus:ump.at(cur)) {
                if (busVis[bus]==1) {
                    continue;
                }
                for (int nxt:routes.at(bus)) {
                    if (vis[nxt]!=INF) {
                        continue;
                    }
                    vis[nxt]=vis[cur]+1;
                    que.push(nxt);
                    if (nxt==target) {
                        return vis[nxt];
                    }
                }
                busVis[bus]=1;
            }
        }
        return -1;
    }
};