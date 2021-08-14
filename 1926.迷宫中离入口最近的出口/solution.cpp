int dir[][2]={{-1,0},{0,-1},{1,0},{0,1}};
const int MAXN=100;
int vis[MAXN][MAXN];
struct node{
    int x,y,step;
};
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row=maze.size(),col=maze.at(0).size();
        memset(vis,0,sizeof(vis));
        queue<node> que;
        que.push({entrance.at(0),entrance.at(1),0});
        vis[entrance.at(0)][entrance.at(1)]=1;
        while (!que.empty()) {
            auto [a,b,ste]=que.front();
            que.pop();
            for (int k=0;k<4;k++) {
                int xx=a+dir[k][0];
                int yy=b+dir[k][1];
                if (!(xx>=0 && xx<row && yy>=0 && yy<col)) {
                    continue;
                }
                if (maze.at(xx).at(yy)=='+') {
                    continue;
                }
                if (vis[xx][yy]==1) {
                    continue;
                }
                if (xx==row-1 || xx==0 || yy==0 || yy==col-1) {
                    return ste+1;
                }
                vis[xx][yy]=1;
                que.push({xx,yy,ste+1});
            }
        }
        return -1;
    }
};