// 把矩阵中的点，当成图中的一个一个点，bfs去判断啥时候到达结尾即可
struct piiv {
    int x,y,val;
};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
const int MAXN=50;
int vis[MAXN][MAXN];
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        memset(vis,0,sizeof(vis));
        int row=grid.size();
        int col=grid.at(0).size();
        if (row==1 && col==1) {
            return grid.at(0).at(0);
        }
        int tar=row*col-1;
        vis[0][0]=1;
        auto func=[](const piiv &A,const piiv &B){
            return A.val>B.val;
        };
        priority_queue<piiv,vector<piiv>,decltype(func)> pq(func);
        pq.push({0,0,grid.at(0).at(0)});
        while (!pq.empty()) {
            auto [x,y,cur]=pq.top();
            pq.pop();
            for (int i=0;i<4;i++) {
                int xx=x+dx[i];
                int yy=y+dy[i];
                if (!(xx>=0 && xx<row && yy>=0 && yy<col)) {
                    continue;
                }
                if (vis[xx][yy]==1) {
                    continue;
                }
                int nxt=max(cur,grid.at(xx).at(yy));
                if (xx==row-1 && yy==col-1) {
                    return nxt;
                }
                vis[xx][yy]=1;
                pq.push({xx,yy,nxt});
            }
        }
        return grid.at(row-1).at(col-1);
    }
};
