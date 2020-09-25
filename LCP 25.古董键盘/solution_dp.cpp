/*
* dp[i][j]表示用了i个字母(1开始)，构建序列长度为j的可能
* 初始化dp[i][0]=1、dp[i][1]=i
  且dp[1][0~min(k,j)]=1
* 转移dp[i][j]
  即使用第i个字母，往i-1个字母的所有可能中插入
  dp[i-1][j-c]*comb[j][c]表示在序列长度中，填c个第i个字母
  那么就有comb[j][c]种挖空法
*/
typedef long long ll;
ll mod=1e9+7;
const int MAXN=130+1;
ll comb[MAXN][MAXN];
bool already_build=false;
void build_comb(int limit)
{
    if (already_build)
        return;
    already_build=true;
    //memset(comb,0,sizeof(comb));
    for (int n=1;n<=limit;++n)
        for (int m=0;m<=n;++m)
        {
            if (m==n || m==0)
                comb[n][m]=1;
            else
                comb[n][m]=(comb[n-1][m]%mod+comb[n-1][m-1]%mod)%mod;
        }
}
class Solution {
public:
    int keyboard(int k, int n) {
        build_comb(MAXN-1);
        vector<vector<int>> dp(27,vector<int>(n+1,0));
        for (int i=1;i<=26;++i)
        {
            dp.at(i).at(0)=1;
            dp.at(i).at(1)=i;
        }
        for (int j=2;j<=min(k,n);++j)
            dp.at(1).at(j)=1;
        for (int i=2;i<=26;++i)
            for (int j=2;j<=n;++j)
                for (int c=0;c<=min(k,j);++c)
                {
                    dp.at(i).at(j)+=dp.at(i-1).at(j-c)*comb[j][c]%mod;
                    dp.at(i).at(j)%=mod;
                }
        return dp.at(26).at(n);
    }
};
