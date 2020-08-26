class Solution {
    vector<int> parent;
    vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int row,column;
    vector<vector<bool>> use;
public:
    bool containsCycle(vector<vector<char>>& grid) {
        row=grid.size();
        column=grid.at(0).size();
        initialise(row,column);
        use=vector<vector<bool>>(row,vector<bool>(column,false));
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
            {
                if (use.at(i).at(j))
                    continue;
                if (!dfs(i,j,grid,-1,-1))
                    return true;
            }
        return false;
    }
    bool dfs(int x,int y,vector<vector<char>>& grid,int l_x,int l_y)
    {
        use.at(x).at(y)=true;
        for (int i=0;i<4;++i)
        {
            int xx=x+dir.at(i).first;
            int yy=y+dir.at(i).second;
            if (!(xx>=0 && xx<row && yy>=0 && yy<column))
                continue;
            if (grid.at(xx).at(yy)!=grid.at(x).at(y))
                continue;
            bool a=union_v(xx*column+yy,x*column+y);
            if (xx!=l_x && yy!=l_y && !a)
                return false;
            if (use.at(xx).at(yy))
                continue;
            if (!dfs(xx,yy,grid,x,y))
                return false;
        }
        return true;
    }
    void initialise(int row,int column)
    {
        int n=row*column;
        parent=vector<int>(row*column);
        for (int i=0;i<n;++i)
            parent.at(i)=i;
    }
    int find_root(int i)
    {
        if (parent.at(i)!=i)
        {
            int ii=find_root(parent.at(i));
            parent.at(i)=ii;
            return ii;
        }
        return i;
    }
    bool union_v(int a,int b)
    {
        int a_root=find_root(a);
        int b_root=find_root(b);
        if (a_root==b_root)
            return false;
        parent.at(a_root)=b_root;
        return true;
    }
};
