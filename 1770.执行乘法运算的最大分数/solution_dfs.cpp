const int MAXM=1e3+1;
int dp[MAXM][MAXM];
const int MINF=0xc0c0c0c0;
class Solution {
    int szA,szB;
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        memset(dp,0xc0,sizeof(dp));
        szA=nums.size();
        szB=mul.size();
        get_dp(nums,mul,0,0);
        return dp[0][0];
    }
    int get_dp(vector<int>& nums, vector<int>& mul,int l,int r) {
        if (dp[l][r]!=MINF) {
            return dp[l][r];
        }
        int idx=l+r;
        if (idx>=szB) {
            return 0;
        }
        dp[l][r]=max(
            mul.at(idx)*nums.at(l)+get_dp(nums,mul,l+1,r),
            mul.at(idx)*nums.at(szA-1-r)+get_dp(nums,mul,l,r+1)
        );
        return dp[l][r];
    }
};
