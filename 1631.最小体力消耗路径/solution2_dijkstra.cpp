/*
 * 把矩阵中每个位置当成图的每一个点
 * 把矩阵中每个位置上下左右可以走的路径，当成点的边
 * 把邻格子之间高度差绝对值，当成是该边的权值
 * 那么就可以构建一个图，且最终答案是高度差绝对值的最大值
 * 那么就可以最短路径之类的算法，求左上角到右下角的最小路径
 */
struct piiv
{
    int x,y,val;
};
const int MAXN=100;
int vis[MAXN][MAXN];
int dis[MAXN][MAXN];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
class Solution {
    int row,col;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        row=heights.size();
        col=heights.at(0).size();
        memset(vis,0,sizeof(vis));
        memset(dis,0x3f,sizeof(dis));
        auto func=[](const piiv &A,const piiv &B){
            return A.val>B.val;
        };
        priority_queue<piiv,vector<piiv>,decltype(func)> pq(func);
        pq.push({0,0,0});
        while (!pq.empty())
        {
            auto [x,y,val]=pq.top();
            pq.pop();
            if (vis[x][y]!=0)
                continue;
            vis[x][y]=1;
            dis[x][y]=val;
            for (int i=0;i<4;++i)
            {
                int xx=x+dx[i];
                int yy=y+dy[i];
                if (!(xx>=0 && xx<row && yy>=0 && yy<col))
                    continue;
                if (vis[xx][yy]!=0)
                    continue;
                int nxt_val=abs(heights.at(xx).at(yy)-heights.at(x).at(y));
                nxt_val=max(nxt_val,val);
                pq.push({xx,yy,nxt_val});
            }
        }
        return dis[row-1][col-1];
    }
};
