/*
* dp[i][j]表示s[i]~s[j]是不是回文串
* 初始化单个字符时一定是回文串dp[i][i]=true;
* 要想dp[i][j]是回文串，则s[i]~s[j]这个串是回文串
  1. 首先要保证两端要相等即s[i]==s[j]
  2. 去除两端后仍是回文串，即s[i+1]~s[j-1]是回文串，但有可能是空串所以要特殊判断下
*/
class Solution {
public:
    int countSubstrings(string s) {
        int s_size=s.size();
        vector<vector<bool>> dp(s_size,vector<bool>(s_size));
        for (int i=0;i<s_size;++i)
            dp.at(i).at(i)=true;
        int ans=s_size;
        for (int j=1;j<s_size;++j)
            for (int i=j-1;i>=0;--i)
                if (s.at(i)==s.at(j) && (i==j-1 || dp.at(i+1).at(j-1)))
                {
                    dp.at(i).at(j)=true;
                    ++ans;
                }
        return ans;
    }
};
