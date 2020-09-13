/*
* dp[i][j]表示s1[0]~s1[i-1]字符串和s2[0]~s2[j]字符串，所需删除字符的ASCII值的最小和
* dp[0][0]则表示两个空串，所以0
* 对于s1的当前处理字符c1，对于当前s2的当前处理字符c2
  1. 如果c1==c2，则代表这两个字符不用删除，则直接忽视这两个字符dp[i-1][j-1]
  2. 如果c1!=c2，至少要删除一个字符，所以取最优即min(c1+dp[i-1][j],c2+dp[i][j-1])
*/
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int s1_size=s1.size();
        int s2_size=s2.size();
        vector<vector<int>> dp(s1_size+1,vector<int>(s2_size+1,INT_MAX/2));
        dp.at(0).at(0)=0;
        for (int i=1;i<=s2_size;++i)
            dp.at(0).at(i)=dp.at(0).at(i-1)+int(s2.at(i-1));
        for (int i=1;i<=s1_size;++i)
            dp.at(i).at(0)=dp.at(i-1).at(0)+int(s1.at(i-1));
        for (int i=1;i<=s1_size;++i)
            for (int j=1;j<=s2_size;++j)
            {
                char c1=s1.at(i-1);
                char c2=s2.at(j-1);
                if (c1!=c2)
                    dp.at(i).at(j)=min((int)c1+dp.at(i-1).at(j),(int)c2+dp.at(i).at(j-1));
                else
                    dp.at(i).at(j)=dp.at(i-1).at(j-1);
            }
        return dp.at(s1_size).at(s2_size);
    }
};
