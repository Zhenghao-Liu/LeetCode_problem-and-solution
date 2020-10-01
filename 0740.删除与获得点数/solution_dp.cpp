//将数组变换，转换为每个值的所有点数。就成了打家劫舍问题
const int MAXN=10001;
int dp[MAXN];
int cnt[MAXN];
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        for (int i:nums)
            ++cnt[i];
        dp[1]=cnt[1];
        for (int i=2;i<MAXN;++i)
            dp[i]=max(dp[i-1],dp[i-2]+cnt[i]*i);
        return dp[MAXN-1];
    }
};
