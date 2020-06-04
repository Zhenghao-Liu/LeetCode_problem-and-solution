//岛屿的周长就是岛屿方格和非岛屿方格相邻的边的数量
class Solution {
    int row,column;
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        row=grid.size();
        if (row==0)
            return 0;
        column=grid.at(0).size();
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (grid.at(i).at(j)==1)
                    return dfs(grid,i,j);
        return -1;
    }
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        //出边界
        if (!(i>=0 && i<row && j>=0 && j<column))
            return 1;
        //出现水
        if (grid.at(i).at(j)==0)
            return 1;
        //已经访问过的节点
        if (grid.at(i).at(j)==2)
            return 0;
        grid.at(i).at(j)=2;
        int up=dfs(grid,i-1,j);
        int down=dfs(grid,i+1,j);
        int left=dfs(grid,i,j-1);
        int right=dfs(grid,i,j+1);
        return up+down+left+right;
    }
};
