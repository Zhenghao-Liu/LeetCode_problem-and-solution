const int MAXL=9+1;
const int MAXT=5e3+1;
int dp[MAXL][MAXT];
const int MINF=0xc0c0c0c0;
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        memset(dp,0xc0,sizeof(dp));
        int sz=cost.size();
        dp[0][0]=0;
        for (int i=1;i<=sz;i++) {
            int cos=cost.at(i-1);
            for (int j=0;j<=target;j++) {
                dp[i][j]=dp[i-1][j];
                if (j>=cos) {
                    dp[i][j]=max(dp[i][j],dp[i][j-cos]+1);
                }
            }
        }
        if (dp[sz][target]<=0) {
            return "0";
        }
        string ans;
        int tar=target;
        for (int i=sz;i>=1;i--) {
            int cos=cost.at(i-1);
            while (tar>=cos && dp[i][tar]==dp[i][tar-cos]+1) {
                tar-=cos;
                ans+=char('0'+i);
            }
        }
        return ans;
    }
};