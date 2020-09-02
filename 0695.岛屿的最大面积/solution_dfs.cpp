int dir_x[]={-1,1,0,0};
int dir_y[]={0,0,-1,1};
class Solution {
    int ans;
    int row,column;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        ans=0;
        row=grid.size();
        column=grid.at(0).size();
        int area=0;
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (grid.at(i).at(j)==1)
                {
                    area=0;
                    dfs(grid,i,j,area);
                }
        return ans;
    }
    void dfs(vector<vector<int>>& grid,int x,int y,int &area)
    {
        grid.at(x).at(y)=2;
        ++area;
        ans=max(ans,area);
        for (int k=0;k<4;++k)
        {
            int xx=x+dir_x[k];
            int yy=y+dir_y[k];
            if (xx>=0 && xx<row && yy>=0 && yy<column && grid.at(xx).at(yy)==1)
                dfs(grid,xx,yy,area);
        }
    }
};
