const int MAXN=500;
int vis[MAXN][MAXN];
typedef pair<int,int> pii;
int dir[][2]={{-1,0},{1,0},{0,-1},{0,1}};
class Solution {
    int row,col;
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        memset(vis,0,sizeof(vis));
        row=grid1.size(),col=grid1.at(0).size();
        int ans=0;
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                if (grid2.at(i).at(j)==1 && vis[i][j]==0 && bfs(grid1,grid2,i,j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
    bool bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int x,int y) {
        bool ans=true;
        vis[x][y]=1;
        queue<pii> que;
        que.push({x,y});
        if (grid1.at(x).at(y)==0) {
            ans=false;
        }
        while (!que.empty()) {
            auto [a,b]=que.front();
            que.pop();
            for (int k=0;k<4;k++) {
                int xx=a+dir[k][0];
                int yy=b+dir[k][1];
                if (!(xx>=0 && xx<row && yy>=0 && yy<col)) {
                    continue;
                }
                if (vis[xx][yy]==1 || grid2.at(xx).at(yy)==0) {
                    continue;
                }
                vis[xx][yy]=1;
                que.push({xx,yy});
                if (grid1.at(xx).at(yy)==0) {
                    ans=false;
                }
            }
        }
        return ans;
    }
};