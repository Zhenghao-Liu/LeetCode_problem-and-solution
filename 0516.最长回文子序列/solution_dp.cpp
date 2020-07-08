/*
* dp[i][j]表示在s中从s[i]~s[j]的最长回文子序列
* 只有一个字母即i==j时dp[i][j]=1因为1个字母就是最长回文子序列
* 若s[i]==s[j]即这两个字母可以构成回文子序列，所以dp[i][j]=2+dp[i+1][j-1]
* 若s[i]!=s[j]即两个边界无法构成回文子序列，那就选择放弃一边即dp[i][j]=max(dp[i+1][j],dp[i][j-1])
* 注意dp与左下方有关，所以注意填充的方向
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty())
            return 0;
        int s_size=s.size();
        vector<vector<int>> dp(s_size,vector<int>(s_size,0));
        for (int i=0;i<s_size;++i)
            dp.at(i).at(i)=1;
        for (int i=s_size-2;i>=0;--i)
            for (int j=i+1;j<s_size;++j)
                if (s.at(i)==s.at(j))
                    dp.at(i).at(j)=2+dp.at(i+1).at(j-1);
                else
                    dp.at(i).at(j)=max(dp.at(i+1).at(j),dp.at(i).at(j-1));
        return dp.at(0).at(s_size-1);
    }
};
