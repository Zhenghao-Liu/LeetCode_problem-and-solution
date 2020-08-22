/*
* 区间dp：设dp[i][j]表示s[i]~s[j]字符打印最少次数
** 那么初始化即单个字符只用打印一次，即dp[i][i]=1
* 那么dp[i][j]自然是要从更小的范围转移过来的，我们设新添加的是s[i]
**  那么自然最基本情况dp[i][j]=1+dp[i+1][j]，即单独打印s[i]
* 假设在s[i+1]~s[j]中有个s[k]，且s[k]==s[i]，
  那么s[i+1]~s[j]可以分成两段s[i+1]~s[k]和s[k+1]~s[j]，
  且因为s[i]==s[k]，所以打印s[i+1]~s[k]时候是可以顺带同时打印s[i]的，即不用+1
**  所以if (s[i]==s[k]) dp[i][j]=min(dp[i][j],dp[i+1][k],dp[k+1][j])
* 这个k是可以到达最右端点即j的，但是方程要改下
**  所以if (s[i]==s[j]) dp[i][j]=min(d[i][j],dp[i+1][j])
* 最后的答案就是dp[0][s.size()-1]
* 注意转移同时依赖左和下方向，注意填表的方向即可
*/
class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty())
            return 0;
        int s_size=s.size();
        vector<vector<int>> dp(s_size,vector<int>(s_size,INT_MAX/2));
        for (int i=0;i<s_size;++i)
            dp.at(i).at(i)=1;
        for (int i=s_size-2;i>=0;--i)
            for (int j=i+1;j<s_size;++j)
            {
                dp.at(i).at(j)=1+dp.at(i+1).at(j);
                for (int k=i+1;k+1<=j;++k)
                    if (s.at(k)==s.at(i))
                        dp.at(i).at(j)=min(dp.at(i).at(j),dp.at(i+1).at(k)+dp.at(k+1).at(j));
                if (s.at(i)==s.at(j))
                    dp.at(i).at(j)=min(dp.at(i).at(j),dp.at(i+1).at(j));
            }
        return dp.at(0).at(s_size-1);
    }
};
