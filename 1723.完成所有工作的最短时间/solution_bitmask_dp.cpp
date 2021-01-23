/*
 * dp[i][j]表示当前考虑到了i个工人时，已经考虑了二进制下j的分工作情况下，的答案
 * 先用sum[j]预处理出当一个人工作在j状态下的工作时间
 * 之后在dp[i][j]情况下，枚举j的补集即剩余未分配的工作，分配给下一个人
 */
const int MAXK=12+1;
const int MAXN=1<<12;
int dp[MAXK][MAXN];
int sum[MAXN];
const int INF=0x3f3f3f3f;
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        memset(dp,0x3f,sizeof(dp));
        memset(sum,0,sizeof(sum));
        int size=jobs.size();
        int ALL=(1<<size)-1;
        for (int i=0;i<=ALL;i++) {
            int ii=i;
            int idx=0;
            while (ii!=0) {
                if ((ii&1)!=0) {
                    sum[i]+=jobs.at(idx);
                }
                idx++;
                ii>>=1;
            }
        }
        dp[0][0]=0;
        for (int i=0;i<k;i++) {
            for (int j=0;j<=ALL;j++) {
                if (dp[i][j]==INF) {
                    continue;
                }
                int notWork=(~j)&ALL;
                int subset=notWork;
                do {
                    int nxt=subset|j;
                    dp[i+1][nxt]=min(dp[i+1][nxt],max(dp[i][j],sum[subset]));
                    subset=(subset-1)&notWork;
                }while(subset!=notWork);
            }
        }
        return dp[k][ALL];
    }
};
