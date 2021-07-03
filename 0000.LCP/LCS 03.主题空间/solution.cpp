const int MAXN=500;
int vis[MAXN][MAXN];
int dir[][2]={{-1,0},{1,0},{0,-1},{0,1}};
class Solution {
    int row,col;
public:
    int largestArea(vector<string>& grid) {
        row=grid.size();
        col=grid.at(0).size();
        memset(vis,0,sizeof(vis));
        int ans=0;
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                if (vis[i][j]==1) {
                    continue;
                }
                int cnt=0;
                bool ok=true;
                dfs(grid,i,j,cnt,ok,grid.at(i).at(j));
                if (ok) {
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
    void dfs(vector<string> &grid,int x,int y,int &cnt,bool &ok,char num) {
        cnt++;
        vis[x][y]=1;
        for (int k=0;k<4;k++) {
            int xx=x+dir[k][0];
            int yy=y+dir[k][1];
            if (!(xx>=0 && xx<row && yy>=0 && yy<col)) {
                ok=false;
                continue;
            }
            if (grid.at(xx).at(yy)=='0') {
                ok=false;
                continue;
            }
            if (vis[xx][yy]==1 || grid.at(xx).at(yy)!=num) {
                continue;
            }
            dfs(grid,xx,yy,cnt,ok,num);
        }
    }
};