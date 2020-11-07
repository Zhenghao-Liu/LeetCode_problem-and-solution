/*
 * 因为用了x位，就不能再用<x位的字符
 * 先统计每一位中有哪些字符，放入cnt中
 * dp[i][j]表示当前考虑到了第i位(以0开始)，且构造到target的第j位(以0开始)
 * 转移
 * 1. 如果采用第i位，则是dp[i-1][j-1]*cnt[i][target[j]-'a']
   2. 如果不采用第i位，那么就是上一行dp[i-1][j]
 */
const int MAXN=1000;
int cnt[MAXN][26];
int dp[MAXN][MAXN];
class Solution {
    int mod=1e9+7;
public:
    int numWays(vector<string>& words, string target) {
        int t_size=target.size();
        int words_size=words.size();
        int w_size=words.at(0).size();
        memset(cnt,0,sizeof(cnt));
        for (string &i:words)
        {
            for (int j=0;j<w_size;++j)
                ++cnt[j][i.at(j)-'a'];
        }
        memset(dp,0,sizeof(dp));
        for (int i=0;i<w_size;++i)
        {
            int idx=target.at(0)-'a';
            dp[i][0]=cnt[i][idx];
            if (i>=1)
            {
                dp[i][0]+=dp[i-1][0];
                dp[i][0]%=mod;
            }
        }
        for (int i=1;i<w_size;++i)
            for (int j=1;j<t_size && j<=i;++j)
            {
                int idx=target.at(j)-'a';
                int a=cnt[i][idx];
                dp[i][j]=(dp[i-1][j]+(long long)dp[i-1][j-1]*a)%mod;
            }
        return dp[w_size-1][t_size-1];
    }
};
