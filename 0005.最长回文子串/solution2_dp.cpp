/**
* dp[i][j]表i~j是否是回文串
* 我们可以得知状态对于一个串判断是否是回文串，先判断两边，再判断里面
* 转移方程
  if [i]==[j]
      dp[i][j]= dp[i+1][j-1] 注意不要越界
                或 (j-1)-(i+1)-1<=1即在两边字符相同情况下，里面的字符长度<=1的情况
* 初始化i<=j且dp[i][i]=true毕竟单个字符一定是回文串
* 注意转移条件是取决于左下的，所以要按列的方式填
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int s_size=s.size();
        int start=0,max_length=1;
        vector<vector<bool>> dp(s_size,vector<bool>(s_size,false));
        for (int i=0;i<s_size;++i)
            dp.at(i).at(i)=true;
        for (int j=1;j<s_size;++j)
            for (int i=0;i<j;++i)
            {
                if (s.at(i)==s.at(j))
                {
                    dp.at(i).at(j)=(j-i<=2) || dp.at(i+1).at(j-1);  
                    if (dp.at(i).at(j) && j-i+1>max_length)
                    {
                        max_length=j-i+1;
                        start=i;
                    }
                }
                else
                    continue;
            }
        return s.substr(start,max_length);
    }
};
