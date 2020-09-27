/*
* dp[i][j]表示S[i]~S[j]的回文子序列
* 若S[i]!=S[j]，则dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1](中间重复算的部分)
* 若S[i]==S[j]==x，因为会有重复，所以需要统计S[i+1]~S[j-1]中间有多少个重复的x
  1. 若没有重复，则dp[i][j]=2*dp[i+1][j-1]+2
     即x···里面的回文序列···x、···里面的回文序列···、xx、x
  2. 若有一个重复，则dp[i][j]=2*dp[i+1][j-1]+1
     即x···里面的回文序列···x、···里面的回文序列···、xx、(因为里面的回文序列会包括x)
  3. 若有多个重复，则需要找到S[i+1]~S[j-1]里面最左边出现x的位置left，和最右边出现x的位置right
     dp[i][j]=2*dp[i+1][j-1]-dp[left+1][right-1]
     因为会重复计算，且xx、x都已经算过了
* 因为减法，所以求余时候要额外加多一个mod
*/
const int MAXN=1000;
int dp[MAXN][MAXN];
class Solution {
    int mod=1e9+7;
public:
    int countPalindromicSubsequences(string S) {
        memset(dp,0,sizeof(dp));
        int size=S.size();
        for (int i=size-1;i>=0;--i)
            for (int j=i;j<size;++j)
            {
                if (i==j)
                {
                    dp[i][j]=1;
                    continue;
                }
                if (S.at(i)!=S.at(j))
                {
                    dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
                    dp[i][j]=(dp[i][j]%mod+mod)%mod;
                }
                else
                {
                    char c=S.at(i);
                    int left=i+1,right=j-1;
                    while (left<=right && S.at(left)!=c)
                        ++left;
                    while (left<=right && S.at(right)!=c)
                        --right;
                    //没有重复的x
                    if (left>right)
                    {
                        dp[i][j]=2*dp[i+1][j-1]+2;
                        dp[i][j]%=mod;
                    }
                    //有一个重复的x
                    else if (left==right)
                    {
                        dp[i][j]=2*dp[i+1][j-1]+1;
                        dp[i][j]%=mod;
                    }
                    //有多个重复的
                    else
                    {
                        dp[i][j]=2*dp[i+1][j-1]-dp[left+1][right-1];
                        dp[i][j]=(dp[i][j]%mod+mod)%mod;
                    }
                }
            }
        return dp[0][size-1];
    }
};
