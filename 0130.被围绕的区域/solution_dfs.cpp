/*
* 本题解释有点误导作用
* 当测试案例[["O","X","X","O","X"],["X","O","O","X","O"],["X","O","X","O","X"],["O","X","O","O","O"],["X","X","O","X","O"]]第三行第四列的O就不符合解释说的情况
* 采用dfs方法
* 从边界的"O"出发dfs
* 找到所有连通的"O"标记为"#"
* 最后把"#"变"O"，"O"变"X"
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        if (row<3)
            return;
        int column=board.at(0).size();
        if (column<3)
            return;
        for (int i=0;i<row;++i)
            if (board.at(i).at(0)=='O')
                dfs(board,i,0,row,column);
        for (int j=1;j<column;++j)
        {
            if (board.at(0).at(j)=='O')
                dfs(board,0,j,row,column);
            if (board.at(row-1).at(j)=='O')
                dfs(board,row-1,j,row,column);
        }
        for (int i=1;i<row-1;++i)
            if (board.at(i).at(column-1)=='O')
                dfs(board,i,column-1,row,column);
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (board.at(i).at(j)=='#')
                    board.at(i).at(j)='O';
                else if (board.at(i).at(j)=='O')
                    board.at(i).at(j)='X';
    }
    void dfs(vector<vector<char>>& board,int i,int j,const int& row,const int& column)
    {
        if (board.at(i).at(j)=='#' || board.at(i).at(j)=='X')
            return;
        board.at(i).at(j)='#';
        if (i>0)
            dfs(board,i-1,j,row,column);
        if (i<row-1)
            dfs(board,i+1,j,row,column);
        if (j>0)
            dfs(board,i,j-1,row,column);
        if (j<column-1)
            dfs(board,i,j+1,row,column);
    }
};
