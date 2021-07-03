typedef long long ll;
const int MAXN=1e5;
ll dp[MAXN][2];// + -
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        int sz=nums.size();
        dp[0][0]=nums.at(0);
        dp[0][1]=0;
        for (int i=1;i<sz;i++) {
            int cur=nums.at(i);
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+cur);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-cur);
        }
        return max(dp[sz-1][0],dp[sz-1][1]);
    }
};