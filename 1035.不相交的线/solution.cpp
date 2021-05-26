const int MAXN=500;
int dp[MAXN][MAXN];
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,0,sizeof(dp));
        int sz1=nums1.size(),sz2=nums2.size();
        dp[0][0]=nums1.at(0)==nums2.at(0) ? 1 : 0;
        for (int j=1;j<sz2;j++) {
            dp[0][j]=nums1.at(0)==nums2.at(j) ? 1 : dp[0][j-1];
        }
        for (int i=1;i<sz1;i++) {
            dp[i][0]=nums1.at(i)==nums2.at(0) ? 1 : dp[i-1][0];
        }
        for (int i=1;i<sz1;i++) {
            for (int j=1;j<sz2;j++) {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if (nums1.at(i)==nums2.at(j)) {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }
        return dp[sz1-1][sz2-1];
    }
};