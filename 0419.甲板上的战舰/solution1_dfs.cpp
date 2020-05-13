//暴力，像岛屿一样搜索但复杂度不是O(n)
class Solution {
    vector<vector<int>> dir{{-1,0},{1,0},{0,1},{0,-1}};
public:
    int countBattleships(vector<vector<char>>& board) {
        int row=board.size();
        if (row==0)
            return 0;
        int column=board.at(0).size();
        vector<vector<bool>> visited(row,vector<bool>(column,false));
        int ans=0;
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (board.at(i).at(j)=='X' && !visited.at(i).at(j))
                {
                    ++ans;
                    dfs(board,row,column,i,j,visited);
                }
        return ans;
    }
    void dfs(vector<vector<char>> &board,const int &row,const int &column,int x,int y,vector<vector<bool>> &visited)
    {
        visited.at(x).at(y)=true;
        int next_x,next_y;
        for (vector<int> &i:dir)
        {
            next_x=x+i.at(0);
            next_y=y+i.at(1);
            if (next_x>=0 && next_x<row && next_y>=0 && next_y<column && !visited.at(next_x).at(next_y) && board.at(next_x).at(next_y)=='X')
                dfs(board,row,column,next_x,next_y,visited);
        }
    }
};
