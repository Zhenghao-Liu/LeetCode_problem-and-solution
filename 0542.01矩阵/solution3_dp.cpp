//单靠向左向上和向右向下(向右向上和向左向下一样可以)两种情况结合其实就能求出所有可能
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if (row==0)
            return {};
        int column=matrix.at(0).size();
        //因为是找最短距离所以求最小值，设初值为一个较大值，但要注意溢出
        vector<vector<int>> dp(row,vector<int>(column,INT_MAX/2));
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (matrix.at(i).at(j)==0)
                    dp.at(i).at(j)=0;
        //假设只能向右向上移动，注意dp顺序
        for (int i=0;i<row;++i)
            for (int j=column-1;j>=0;--j)
            {
                if (dp.at(i).at(j)==0)
                    continue;
                if (j+1<column)
                    dp.at(i).at(j)=min(dp.at(i).at(j),dp.at(i).at(j+1)+1);
                if (i-1>=0)
                    dp.at(i).at(j)=min(dp.at(i).at(j),dp.at(i-1).at(j)+1);
            }
        //假设只能向左向下移动，注意dp顺序
        for (int i=row-1;i>=0;--i)
            for (int j=0;j<column;++j)
            {
                if (dp.at(i).at(j)==0)
                    continue;
                if (j-1>=0)
                    dp.at(i).at(j)=min(dp.at(i).at(j),dp.at(i).at(j-1)+1);
                if (i+1<row)
                    dp.at(i).at(j)=min(dp.at(i).at(j),dp.at(i+1).at(j)+1);
            }
        return dp;
    }
};
