const int MAX_S1=12+1;
const int MAX_ALLS2=1<<12;
int dp[MAX_S1][MAX_ALLS2];
class Solution {
    int INF=0x3f3f3f3f;
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        memset(dp,0x3f,sizeof(dp));
        int s1=cost.size();
        int s2=cost.at(0).size();
        //s2状态的全集
        int ALLs2=(1<<s2)-1;
        dp[0][0]=0;
        for (int i=0;i<s1;++i)
            for (int j=0;j<=ALLs2;++j)
            {
                if (dp[i][j]==INF)
                    continue;
                //策略1:左侧第i个点，连接右侧若干个未连接的点
                int not_connected=(~j)&ALLs2;
                int subset=not_connected;
                do
                {
                    if (subset==0)
                        break;
                    int nxt=subset|j;
                    int price=0;
                    for (int k=0;k<s2;++k)
                        if ((subset&(1<<k))!=0)
                            price+=cost.at(i).at(k);
                    dp[i+1][nxt]=min(dp[i+1][nxt],dp[i][j]+price);
                    subset=(subset-1)&not_connected;
                }while(subset!=not_connected);
                //策略2:左侧第i个点，连接右侧一个已连接的点
                for (int connected=0;connected<s2;++connected)
                    if ((j&(1<<connected))!=0)
                    {
                        int price=cost.at(i).at(connected);
                        int nxt=j;
                        dp[i+1][nxt]=min(dp[i+1][nxt],dp[i][j]+price);
                    }
            }
        return dp[s1][ALLs2];
    }
};
