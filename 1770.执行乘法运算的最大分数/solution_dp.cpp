const int MAXN=1e3+1;
int dp[MAXN][MAXN];
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int numsSz=nums.size();
        int mulSz=mul.size();
        memset(dp,0,sizeof(dp));
        for (int i=0;i<=mulSz;i++) {
            dp[i][mulSz-i]=0;
        }
        for (int j=mulSz-1;j>=0;j--) {
            for (int i=mulSz-j-1;i>=0;i--) {
                int idx=i+j;
                dp[i][j]=max(
                    nums.at(i)*mul.at(idx)+dp[i+1][j],
                    nums.at(numsSz-1-j)*mul.at(idx)+dp[i][j+1]
                );
            }
        }
        return dp[0][0];
    }
};
