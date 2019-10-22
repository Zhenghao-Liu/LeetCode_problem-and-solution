//整体思路和前两题一样
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size(),column=grid.at(0).size();
        vector<vector<int>> dp(row,vector<int>(column,0));
        dp.at(0).at(0)=grid.at(0).at(0);
        for (int i=1;i<column;++i)
            dp.at(0).at(i)=dp.at(0).at(i-1)+grid.at(0).at(i);
        for (int i=1;i<row;++i)
            dp.at(i).at(0)=dp.at(i-1).at(0)+grid.at(i).at(0);
        for (int i=1;i<row;++i)
            for (int j=1;j<column;++j)
                dp.at(i).at(j)=min(dp.at(i-1).at(j),dp.at(i).at(j-1))+grid.at(i).at(j);
        return dp.at(row-1).at(column-1);
    }
};
