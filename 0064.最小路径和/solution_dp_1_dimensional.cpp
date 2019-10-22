/*
* 整体思路和前两题一样
* 压缩了空间复杂度为O(N)
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size(),column=grid.at(0).size();
        vector<int> dp(column,0);
        dp.at(0)=grid.at(0).at(0);
        for (int i=1;i<column;++i)
            dp.at(i)=dp.at(i-1)+grid.at(0).at(i);
        for (int i=1;i<row;++i)
        {
            dp.at(0)=grid.at(i).at(0)+dp.at(0);
            for (int j=1;j<column;++j)
                dp.at(j)=min(dp.at(j-1),dp.at(j))+grid.at(i).at(j);
        }    
        return dp.at(column-1);
        
    }
};
