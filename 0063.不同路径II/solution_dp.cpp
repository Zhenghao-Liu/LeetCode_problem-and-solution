//整体思路和上一题一样
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.at(0).at(0)==1)
            return 0;
        int row=obstacleGrid.size(),column=obstacleGrid.at(0).size();
        vector<vector<long long int>> dp(row,vector<long long int>(column,0));
        dp.at(0).at(0)=1;
        for (int i=1;i<column;++i)
            if (obstacleGrid.at(0).at(i)!=1)
                dp.at(0).at(i)=dp.at(0).at(i-1);
            else
                dp.at(0).at(i)=0;
        for (int i=1;i<row;++i)
            if (obstacleGrid.at(i).at(0)!=1)
                dp.at(i).at(0)=dp.at(i-1).at(0);
            else
                dp.at(i).at(0)=0;
        for (int i=1;i<row;++i)
            for (int j=1;j<column;++j)
                if (obstacleGrid.at(i).at(j)==1)
                    dp.at(i).at(j)=0;
                else
                    dp.at(i).at(j)=dp.at(i-1).at(j)+dp.at(i).at(j-1);
        return dp.at(row-1).at(column-1);   
    }
};
