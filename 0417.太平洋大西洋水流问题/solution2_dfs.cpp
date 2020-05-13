//从海洋往里走，用两个visited更方便
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
            dfs(matrix,row,column,-1,j,-1,Pacific);
            dfs(matrix,row,column,row,j,-1,Atlantic);
        }
        for (int i=0;i<row;++i)
        {
            dfs(matrix,row,column,i,-1,-1,Pacific);
            dfs(matrix,row,column,i,column,-1,Atlantic);
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
        int next_x,next_y;
        for (vector<int> &i:dir)
        {
            next_x=x+i.at(0);
            next_y=y+i.at(1);
            if (next_x>=0 && next_x<row && next_y>=0 && next_y<column && matrix.at(next_x).at(next_y)>=value && !visited.at(next_x).at(next_y))
            {
                visited.at(next_x).at(next_y)=true;
                dfs(matrix,row,column,next_x,next_y,matrix.at(next_x).at(next_y),visited);
            }
        }
    }
};
