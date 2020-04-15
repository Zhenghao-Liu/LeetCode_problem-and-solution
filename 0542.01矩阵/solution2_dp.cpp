/*
* 从1到最近的0就只有4种情况：
* 向左和向上
  向左和向下
  向右和向上
  向右和向下
* 那就可以从4种情况进行dp，取最大值
* 但是要注意dp是前面的结果推导出后面的结果，因此dp的顺序要定好
* 例如向左和向下，则初始元素是左下角的元素，所以要从i=row-1 j=0开始dp
*/
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
        //假设只能向左向上移动
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
            {
                if (dp.at(i).at(j)==0)
                    continue;
                if (j-1>=0)
                    dp.at(i).at(j)=min(dp.at(i).at(j),dp.at(i).at(j-1)+1);
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
        //假设只能向右向下移动，注意dp顺序
        for (int i=row-1;i>=0;--i)
            for (int j=column-1;j>=0;--j)
            {
                if (dp.at(i).at(j)==0)
                    continue;
                if (j+1<column)
                    dp.at(i).at(j)=min(dp.at(i).at(j),dp.at(i).at(j+1)+1);
                if (i+1<row)
                    dp.at(i).at(j)=min(dp.at(i).at(j),dp.at(i+1).at(j)+1);
            }
        return dp;
    }
};
