/*
* 整体思路和二维的一样
* 时间复杂度依然为O(N^2)，空间复杂度优化为O(N)(二维为O(N^2))
* 因为dp[i][j]=dp[i-1][j]+dp[i][j-1]
* 所以可以直接用上一行的值搬移下来，dp[j]=d[j-1]+dp[j]
* 优化为一个一维数组
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(m,1);
        for (int i=1;i<n;++i)
            for (int j=1;j<m;++j)
                dp.at(j)=dp.at(j-1)+dp.at(j);
        return dp.at(m-1);
    }
};
