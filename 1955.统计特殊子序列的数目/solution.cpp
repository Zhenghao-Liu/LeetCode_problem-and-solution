typedef long long ll;
const int MAXN=1e5;
ll mod=1e9+7;
ll dp[MAXN][3];
class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        int sz=nums.size();
        dp[0][0]=nums.at(0)==0 ? 1 : 0;
        for (int i=1;i<sz;i++) {
            int cur=nums.at(i);
            
            dp[i][0]+=dp[i-1][0];
            dp[i][0]%=mod;
            if (cur==0) {
                dp[i][0]+=dp[i-1][0];
                dp[i][0]%=mod;
                dp[i][0]++;
                dp[i][0]%=mod;
            }
            
            dp[i][1]+=dp[i-1][1];
            dp[i][1]%=mod;
            if (cur==1) {
                dp[i][1]+=dp[i-1][1];
                dp[i][1]%=mod;
                dp[i][1]+=dp[i-1][0];
                dp[i][1]%=mod;
            }
            
            dp[i][2]+=dp[i-1][2];
            dp[i][2]%=mod;
            if (cur==2) {
                dp[i][2]+=dp[i-1][2];
                dp[i][2]%=mod;
                dp[i][2]+=dp[i-1][1];
                dp[i][2]%=mod;
            }
        }
        
        return dp[sz-1][2];
    }
};