//滚动数组
class Solution {
    int base=1e9+7;
public:
    int checkRecord(int n) {
        //dp[i][j][k]表长度为i，结尾有j个‘L’，带有K个‘A’的个数
        long long a=1;//[i][0][0]
        long long b=1;//[i][0][1]
        long long c=1;//[i][1][0]
        long long d=0;//[i][1][1]
        long long e=0;//[i][2][0]
        long long f=0;//[i][2][1]
        long long _a,_b,_c,_d,_e,_f;
        for (int i=2;i<=n;++i)
        {
            // dp[i][0][0]=(dp[i-1][0][0]+dp[i-1][1][0]+dp[i-1][2][0])%base;
            // dp[i][0][1]=(dp[i-1][0][1]+dp[i-1][1][1]+dp[i-1][2][1]+dp[i][0][0])%base;
            // dp[i][1][0]=dp[i-1][0][0]%base;
            // dp[i][1][1]=dp[i-1][0][1]%base;
            // dp[i][2][0]=dp[i-1][1][0]%base;
            // dp[i][2][1]=dp[i-1][1][1]%base;
            _a=a,_b=b,_c=c,_d=d,_e=e,_f=f;
            a=(_a+_c+_e)%base;
            b=(_b+_d+_f+a)%base;
            c=_a%base;
            d=_b%base;
            e=_c%base;
            f=_d%base;
        }
        return (a+b+c+d+e+f)%base;
    }
};
