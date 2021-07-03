const int MAXN=1e4;
int dp[MAXN];
const int INF=0x3f3f3f3f;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        memset(dp,0x3f,sizeof(dp));
        for (string &i:deadends) {
            int num=stoi(i);
            dp[num]=-1;
        }
        int tar=stoi(target);
        if (dp[0]==-1 || dp[tar]==-1) {
            return -1;
        }
        if (tar==0) {
            return 0;
        }
        dp[0]=0;
        queue<int> que;
        vector<int> dir{-1,1};
        que.push(0);
        while (!que.empty()) {
            int cur=que.front();
            que.pop();
            int ori=cur;
            for (int i=1;i<1e4;i*=10) {
                int now=ori%10;
                ori/=10;
                for (int j:dir) {
                    int jj=now+j;
                    if (jj==10) {
                        jj=0;
                    } else if (jj==-1) {
                        jj=9;
                    }
                    int num=cur-now*i+jj*i;
                    if (dp[num]==-1 || dp[num]!=INF) {
                        continue;
                    }
                    dp[num]=dp[cur]+1;
                    if (num==tar) {
                        return dp[num];
                    }
                    que.push(num);
                }
            }
        }
        return -1;
    }
};