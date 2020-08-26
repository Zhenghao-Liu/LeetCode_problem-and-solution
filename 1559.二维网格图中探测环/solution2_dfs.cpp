class Solution {
    vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int row,column;
    vector<vector<bool>> use;
public:
    bool containsCycle(vector<vector<char>>& grid) {
        row=grid.size();
        column=grid.at(0).size();
        use=vector<vector<bool>>(row,vector<bool>(column,false));
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
            {
                if (use.at(i).at(j))
                    continue;
                if (dfs(i,j,grid,-1,-1))
                    return true;
            }
        return false;
    }
    bool dfs(int x,int y,vector<vector<char>>& grid,int p_x,int p_y)
    {
        use.at(x).at(y)=true;
        for (int i=0;i<4;++i)
        {
            int xx=x+dir.at(i).first;
            int yy=y+dir.at(i).second;
            if (!(xx>=0 && xx<row && yy>=0 && yy<column))
                continue;
            if (xx==p_x && yy==p_y)
                continue;
            if (grid.at(xx).at(yy)!=grid.at(x).at(y))
                continue;
            if (use.at(xx).at(yy))
                return true;
            if (dfs(xx,yy,grid,x,y))
                return true;
        }
        return false;
    }
};
