/*
* 0->0=2
* 0->1=3
* 1->0=4
* 1->1=5
*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row=board.size();
        if (row==0)
            return;
        int column=board.at(0).size();
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                helper(board,row,column,i,j);
        for (vector<int> &i:board)
            for (int &j:i)
                if (j==2 || j==4)
                    j=0;
                else
                    j=1;
    }
    void helper(vector<vector<int>>& board,const int & row,const int & column,int x,int y)
    {
        int alive=0,left,right,up,down;
        up=x>0 ? x-1 : 0;
        down=x+1<row ? x+2 : row;
        left=y>0 ? y-1 : 0;
        right=y+1<column ? y+2 : column;
        for (int i=up;i!=down;++i)
            for (int j=left;j!=right;++j)
                if (i!=x || j!=y)
                {
                    int temp=board.at(i).at(j);
                    if (temp==1 || temp==4 || temp==5)
                        ++alive;
                }
        if (board.at(x).at(y)==1)
        {
            if (alive==2 || alive==3)
                board.at(x).at(y)=5;
            else
                board.at(x).at(y)=4;
        }
        else
        {
            if (alive==3)
                board.at(x).at(y)=3;
            else
                board.at(x).at(y)=2;
        }
    }
};
