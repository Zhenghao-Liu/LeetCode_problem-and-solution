/*
* dp[i][j]表示当前字符长度为i，剪贴板字符长度为j的最少实现步数
  即i>=j
* dp[i-j][j]+1 -> dp[i][j]即原有字符粘贴了j个后得到现总共有i个字符
* dp[i][i]则需要先得到长度为i的字符，再增加一步复制到剪贴板，
  所以dp[i][i]是min(dp[i][所有j])+1
* 最后答案就是min(dp[n][所有的j])
  其实也就是dp[n][n]-1
*/
class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX/2));
        dp.at(1).at(0)=0;
        dp.at(1).at(1)=1;
        for (int i=2;i<=n;++i)
        {
            int min_value=INT_MAX;
            for (int j=i-1;j>0;--j)
            {
                dp.at(i).at(j)=min(dp.at(i).at(j),dp.at(i-j).at(j)+1);
                min_value=min(min_value,dp.at(i).at(j));
            }
            dp.at(i).at(i)=min_value+1;
        }
        return dp.at(n).at(n)-1;
    }
};
