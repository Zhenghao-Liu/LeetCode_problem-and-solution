/**
* 完全背包二维问题
* dp[i][j][k]为处理到第i个字符，拥有j个0，k个1的情况下最多能够组建多少个字符串
* 倘若不组建该字符串dp[i][j][k]=dp[i-1][j][k]
* 倘若组建该字符串dp[i][j][k]=dp[i-1][j-zero][k-one]+1
* 所以答案是dp[strs_size][m][n]
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int strs_size=strs.size();
        vector<vector<vector<int>>> dp(strs_size+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for (int i=1;i<=strs_size;++i)
        {
            pair<int,int> count=count_zero_one(strs.at(i-1));
            int zero=count.first;
            int one=count.second;
            for (int j=0;j<=m;++j)
                for (int k=0;k<=n;++k)
                {
                    dp.at(i).at(j).at(k)=dp.at(i-1).at(j).at(k);
                    if (j>=zero && k>=one)
                        dp.at(i).at(j).at(k)=max(dp.at(i).at(j).at(k),dp.at(i-1).at(j-zero).at(k-one)+1);
                }
        }
        return dp.at(strs_size).at(m).at(n);
    }
    pair<int,int> count_zero_one(string &s)
    {
        int zero=0,one=0;
        for (char &i:s)
            if (i=='0')
                ++zero;
            else
                ++one;
        return {zero,one};
    }
};
