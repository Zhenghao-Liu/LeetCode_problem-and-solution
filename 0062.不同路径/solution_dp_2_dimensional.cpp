/*
* 最为常规的做法：
* 任何一个点都可以转化为：到达它的左边的一个点再往右走一步+到底它的上边一个点再往下走一步
* dp[i][j]=dp[i-1][j]+dp[i][j-1]
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp.at(0).at(0)=1;
        for (int i=1;i<m;++i)
            dp.at(0).at(i)=1;
        for (int i=1;i<n;++i)
            dp.at(i).at(0)=1;
        for (int i=1;i<n;++i)
            for (int j=1;j<m;++j)
                dp.at(i).at(j)=dp.at(i-1).at(j)+dp.at(i).at(j-1);
        return dp.at(n-1).at(m-1);
    }
};
