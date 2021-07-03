const int MAXN=14;
int dp[MAXN][1<<MAXN];
const int INF=0x3f3f3f3f;
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,0x3f,sizeof(dp));
        int sz1=nums1.size(),sz2=nums2.size();
        for (int j=0;j<sz2;j++) {
            dp[0][1<<j]=nums1.at(0)^nums2.at(j);
        }
        int all=(1<<sz2)-1;
        for (int i=1;i<sz1;i++) {
            for (int j=1;j<=all;j++) {
                if (__builtin_popcount(j)!=i) {
                    continue;
                }
                for (int k=0;k<sz2;k++) {
                    if (((1<<k)&j)==0) {
                        dp[i][j|(1<<k)]=min(dp[i][j|(1<<k)],dp[i-1][j]+(nums1.at(i)^nums2.at(k)));
                    }
                }
            }
        }
        return dp[sz1-1][all];
    }
};