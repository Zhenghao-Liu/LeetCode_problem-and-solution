/*
* dp.at(i).at(j)=min(dp.at(i-1).at(j),dp.at(i-1).at(j-1),dp.at(i).at(j-1))+1;
* dp存每一个节点可构成正方形最大的边长
* 再用answer来记录可构成正方形的最大边长
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        if (row==0)
            return 0;
        int column=matrix.at(0).size();
        int answer=0;
        vector<vector<int>> dp(row,vector<int>(column,0));
        for (int j=0;j<column;++j)
            if (matrix.at(0).at(j)=='1')
            {
                dp.at(0).at(j)=1;
                if (answer==0)
                    answer=1;
            }
        for (int i=1;i<row;++i)
            if (matrix.at(i).at(0)=='1')
            {
                dp.at(i).at(0)=1;
                if (answer==0)
                    answer=1;
            }
        for (int i=1;i<row;++i)
            for (int j=1;j<column;++j)
                if (matrix.at(i).at(j)=='1')
                {
                    dp.at(i).at(j)=min(dp.at(i-1).at(j),min(dp.at(i-1).at(j-1),dp.at(i).at(j-1)))+1;
                    if (dp.at(i).at(j)>answer)
                        answer=dp.at(i).at(j);
                }
        return answer*answer;
    }
};
