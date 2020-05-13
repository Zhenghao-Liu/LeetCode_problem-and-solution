//因为海边的一定能进海，直接从边进行dfs就可以
class Solution {
    vector<vector<int>> dir{{-1,0},{1,0},{0,1},{0,-1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if (row==0)
            return {};
        int column=matrix.at(0).size();
        vector<vector<bool>> Pacific(row,vector<bool>(column,false));
        vector<vector<bool>> Atlantic(row,vector<bool>(column,false));
        for (int j=0;j<column;++j)
        {
            dfs(matrix,row,column,0,j,matrix.at(0).at(j),Pacific);
            dfs(matrix,row,column,row-1,j,matrix.at(row-1).at(j),Atlantic);
        }
        for (int i=0;i<row;++i)
        {
            dfs(matrix,row,column,i,0,matrix.at(i).at(0),Pacific);
            dfs(matrix,row,column,i,column-1,matrix.at(i).at(column-1),Atlantic);
        }   
        vector<vector<int>> ans;
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (Pacific.at(i).at(j) && Atlantic.at(i).at(j))
                    ans.push_back({i,j});
        return ans;
    }
    void dfs(vector<vector<int>> &matrix,const int &row,const int &column,int x,int y,int value,vector<vector<bool>> &visited)
    {
        visited.at(x).at(y)=true;
        int next_x,next_y;
        for (vector<int> &i:dir)
        {
            next_x=x+i.at(0);
            next_y=y+i.at(1);
            if (next_x>=0 && next_x<row && next_y>=0 && next_y<column && matrix.at(next_x).at(next_y)>=value && !visited.at(next_x).at(next_y))
                dfs(matrix,row,column,next_x,next_y,matrix.at(next_x).at(next_y),visited);
        }
    }
};
