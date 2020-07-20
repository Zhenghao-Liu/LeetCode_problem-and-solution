const int MAXN=100001;
long long dp[MAXN][3][2];
class Solution {
    int base=1e9+7;
public:
    int checkRecord(int n) {
        //dp[i][j][k]表长度为i，结尾有j个‘L’，带有K个‘A’的个数
        dp[1][0][0]=1;
        dp[1][1][0]=1;
        dp[1][0][1]=1;
        for (int i=2;i<=n;++i)
        {
            dp[i][0][0]=(dp[i-1][0][0]+dp[i-1][1][0]+dp[i-1][2][0])%base;
            dp[i][0][1]=(dp[i-1][0][1]+dp[i-1][1][1]+dp[i-1][2][1]+dp[i][0][0])%base;
            dp[i][1][0]=dp[i-1][0][0]%base;
            dp[i][1][1]=dp[i-1][0][1]%base;
            dp[i][2][0]=dp[i-1][1][0]%base;
            dp[i][2][1]=dp[i-1][1][1]%base;
        }
        long long ans=0;
        for (int i=0;i<3;++i)
            for (int j=0;j<2;++j)
            {
                ans+=dp[n][i][j];
                ans%=base;
            }
        return (int)ans;
    }
};
