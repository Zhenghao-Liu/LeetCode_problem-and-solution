/*
* dp[k][i][j]
  表示S[i]~S[j]中且S[i]==S[j]=='a'+k的回文子序列数
* 1. 若S[i]!='a'+k，则dp[k][i][j]=dp[k][i+1][j]
  2. 若S[j]!='a'+k，则dp[k][i][j]=dp[k][i][j-1]
  3. 若S[i]==S[j]=='a'+k，则本身有2个回文子序列：S[i]、S[i]S[j];再加上内部所有可能即
     dp[k][i][j]=2+dp[0~3][i+1][j-1]
* 注意i==j和i+1==j的边界情况
* 最终答案就是dp[0~3][0][S.size()-1]
*/
const int MAXK=4;
const int MAXN=1000;
int dp[MAXK][MAXN][MAXN];
class Solution {
    int mod=1e9+7;
public:
    int countPalindromicSubsequences(string S) {
        memset(dp,0,sizeof(dp));
        int size=S.size();
        for (int i=size-1;i>=0;--i)
            for (int j=i;j<size;++j)
                for (int k=0;k<MAXK;++k)
                {
                    char c=k+'a';
                    if (i==j)
                    {
                        dp[k][i][j]= S.at(i)==c ? 1 : 0;
                    }
                    else
                    {
                        if (S.at(i)!=c)
                            dp[k][i][j]=dp[k][i+1][j];
                        else if (S.at(j)!=c)
                            dp[k][i][j]=dp[k][i][j-1];
                        else
                        {
                            if (i+1==j)
                                dp[k][i][j]=2;
                            else
                            {
                                dp[k][i][j]=2;
                                for (int kk=0;kk<MAXK;++kk)
                                {
                                    dp[k][i][j]+=dp[kk][i+1][j-1];
                                    dp[k][i][j]%=mod;
                                }
                            }
                        }
                    }
                }
        int ans=0;
        for (int k=0;k<MAXK;++k)
        {
            ans+=dp[k][0][size-1];
            ans%=mod;
        }
        return ans;
    }
};
