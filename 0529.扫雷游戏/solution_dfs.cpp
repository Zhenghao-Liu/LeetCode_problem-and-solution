class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row=board.size(),column=board.at(0).size();
        int x=click.at(0),y=click.at(1);
        if (board.at(x).at(y)=='M')
        {
            board.at(x).at(y)='X';
            return board;
        }
        dfs(board,row,column,x,y);
        return board;
    }
    void dfs(vector<vector<char>>& board,int row,int column,int x,int y)
    {
        if (board.at(x).at(y)!='E')
            return;
        int count_mine=0;
        for (int i=x-1;i!=x+2;++i)
            for (int j=y-1;j!=y+2;++j)
            {
                if (i==x && j==y)
                    continue;
                if (!(i>=0 && i<row && j>=0 && j<column))
                    continue;
                if (board.at(i).at(j)=='M')
                    ++count_mine;
            }
        if (count_mine!=0)
        {
            board.at(x).at(y)=char('0'+count_mine);
        }
        else
        {
            board.at(x).at(y)='B';
            for (int i=x-1;i!=x+2;++i)
                for (int j=y-1;j!=y+2;++j)
                {
                    if (i==x && j==y)
                        continue;
                    if (!(i>=0 && i<row && j>=0 && j<column))
                        continue;
                    dfs(board,row,column,i,j);
                }
        }
        return;
    }
};
