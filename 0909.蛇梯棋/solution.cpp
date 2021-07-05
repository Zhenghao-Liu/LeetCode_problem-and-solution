const int MAXN=20;
int vis[MAXN*MAXN+1];
const int MAXS=6;
const int INF=0x3f3f3f3f;
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int tar=n*n;
        vector<int> vec;
        vec.reserve(n*n+1);
        vec.push_back(0);
        int j=-1,step=-1;
        for (int i=n-1;i>=0;i--) {
            step*=-1;
            for (j= j==-1 ? 0 : n-1;j>=0 && j<n;j+=step) {
                vec.push_back(board.at(i).at(j));
            }
        }
        queue<int> que;
        que.push(1);
        memset(vis,0x3f,sizeof(vis));
        vis[1]=0;
        while (!que.empty()) {
            int cur=que.front();
            que.pop();
            for (int s=1;s<=MAXS;s++) {
                int nxt=cur+s;
                if (vec.at(nxt)!=-1) {
                    nxt=vec.at(nxt);
                }
                if (vis[nxt]!=INF) {
                    continue;
                }
                vis[nxt]=vis[cur]+1;
                if (nxt==tar) {
                    return vis[nxt];
                }
                que.push(nxt);
            }
        }
        return -1;
    }
};