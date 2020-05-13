//因为战舰要么是一条横或者一条竖，所以判断一下横或竖两种情况就知道有没有重复了
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int row=board.size();
        if (row==0)
            return 0;
        int column=board.at(0).size();
        int ans=0;
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (board.at(i).at(j)=='X')
                {
                    if (j-1>=0 && board.at(i).at(j-1)=='X')
                        --ans;
                    else if (i-1>=0 && board.at(i-1).at(j)=='X')
                        --ans;
                    ++ans;
                }
        return ans;
    }
};
