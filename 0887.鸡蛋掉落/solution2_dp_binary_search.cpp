/*
* unsolved1虽然超时但是思路正确
* 优化就是发现dp[a-1][j-1]是随a单调递增序列，而dp[i-a][j]是随着a单调递减序列
* 要想找到二者的min(max())，其实是一个x型的两条直线的交点处
* 其实就是找dp[a-1][j-1]<=dp[i-a][j]的竟可能大的a
*/
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N+1,vector<int>(K+1,0));
        for (int i=1;i<=K;++i)
            dp.at(1).at(i)=1;
        for (int i=2;i<=N;++i)
            dp.at(i).at(1)=i;
        for (int i=2;i<=N;++i)
            for (int j=2;j<=K;++j)
            {
                int left=1,right=i;
                while (left<right)
                {
                    int mid=left+((right-left+1)>>1);
                    int break_count=dp.at(mid-1).at(j-1);
                    int not_break_count=dp.at(i-mid).at(j);
                    if (break_count>not_break_count)
                        right=mid-1;
                    else
                        left=mid;
                }
                dp.at(i).at(j)=1+max(dp.at(left-1).at(j-1),dp.at(i-left).at(j));
            }
        return dp.at(N).at(K);
    }
};
