/*
* dp[i][j]表示直到word1[i]和word2[j]时，最少删除几个字符使得相等
* dp[0][0]看word1[0]看word2[0]是否相等，相等则不用删即0，不等则要删2次即2
* 然后第一行初始化以及第一列初始化
* 如果word1[i]==word2[j]则dp[i][j]=dp[i-1][j-1]，即当前字符相等，那么可以无视这个相同的字符
  若word1[i]!=word2[j]，则必然是要删除的，则比较dp[i-1][j],dp[i][j-1]，并且+1
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1_size=word1.size();
        int w2_size=word2.size();
        if (word1.empty())
            return w2_size;
        else if (word2.empty())
            return w1_size;
        vector<vector<int>> dp(w1_size,vector<int>(w2_size));
        dp.at(0).at(0)= word1.at(0)==word2.at(0) ? 0 : 2;
        for (int j=1;j<w2_size;++j)
        {
            if (word2.at(j)!=word1.at(0))
                dp.at(0).at(j)=dp.at(0).at(j-1)+1;
            else
                dp.at(0).at(j)=j;
        }
        for (int i=1;i<w1_size;++i)
        {
            if (word1.at(i)!=word2.at(0))
                dp.at(i).at(0)=dp.at(i-1).at(0)+1;
            else
                dp.at(i).at(0)=i;
        }
        for (int i=1;i<w1_size;++i)
            for (int j=1;j<w2_size;++j)
            {
                if (word1.at(i)==word2.at(j))
                    dp.at(i).at(j)=dp.at(i-1).at(j-1);
                else
                    dp.at(i).at(j)=1+min(dp.at(i-1).at(j),dp.at(i).at(j-1));
            }
        return dp.at(w1_size-1).at(w2_size-1);
    }
};
