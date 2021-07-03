// dp[i][j]表示考虑到dist[i]，跳了j次休息时间的，最小到达时间
// 注意ceil因为是向上取整，所以要减去eps
const int MAXN=1e3;
double dp[MAXN][MAXN];
const double eps=1e-8;
class Solution {
public:
    int minSkips(vector<int>& dist, double speed, int hoursBefore) {
        int sum=accumulate(dist.begin(),dist.end(),0);
        if (double(sum)/speed>(double)hoursBefore) {
            return -1;
        }
        int sz=dist.size();
        for (int i=0;i<sz;i++) {
            for (int j=0;j<sz;j++) {
                dp[i][j]=INT_MAX/2;
            }
        }
        dp[0][0]=dist.at(0)/speed;
        for (int i=1;i<sz;i++) {
            dp[i][0]=ceil(dp[i-1][0]-eps)+dist.at(i)/speed;
        }
        int tmp=dist.at(0);
        for (int i=1;i<sz;i++) {
            tmp+=dist.at(i);
            dp[i][i]=tmp/speed;
        }
        for (int i=2;i<sz;i++) {
            for (int j=1;j<i;j++) {
                dp[i][j]=min(
                    ceil(dp[i-1][j]-eps)+dist.at(i)/speed,
                    dp[i-1][j-1]+dist.at(i)/speed
                );
            }
        }
        for (int j=0;j<sz;j++) {
            if (dp[sz-1][j]<=double(hoursBefore)) {
                return j;
            }
        }
        return -1;
    }
};