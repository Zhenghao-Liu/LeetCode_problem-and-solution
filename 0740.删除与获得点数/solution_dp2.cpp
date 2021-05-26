//dp[i][0]表示不拿,dp[i][1]表示拿
const int MAXN=10001;
int dp[MAXN][2];
int cnt[MAXN];
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        for (int i:nums)
            ++cnt[i];
        dp[1][0]=0;
        dp[1][1]=cnt[1];
        for (int i=2;i<MAXN;++i)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+cnt[i]*i;
        }
        return max(dp[MAXN-1][0],dp[MAXN-1][1]);
    }
};