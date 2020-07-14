typedef pair<int,int> pii;
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
        queue<pii> helper;
        helper.push({x,y});
        while (!helper.empty())
        {
            auto [cur_x,cur_y]=helper.front();
            helper.pop();
            int count_mine=0;
            for (int i=cur_x-1;i!=cur_x+2;++i)
                for (int j=cur_y-1;j!=cur_y+2;++j)
                {
                    if (!(i>=0 && i<row && j>=0 && j<column))
                        continue;
                    if (i==cur_x && j==cur_y)
                        continue;
                    if (board.at(i).at(j)=='M')
                        ++count_mine;
                }
            if (count_mine!=0)
            {
                board.at(cur_x).at(cur_y)=char('0'+count_mine);
            }
            else
            {
                board.at(cur_x).at(cur_y)='B';
                for (int i=cur_x-1;i!=cur_x+2;++i)
                    for (int j=cur_y-1;j!=cur_y+2;++j)
                    {
                        if (!(i>=0 && i<row && j>=0 && j<column))
                            continue;
                        if (i==cur_x && j==cur_y)
                            continue;
                        if (board.at(i).at(j)!='E')
                            continue;
                        helper.push({i,j});
                        //提前将他改变成访问过的标志，就不用开额外数组判断了
                        board.at(i).at(j)='B';
                    }
            }
        }
        return board;
    }
};
