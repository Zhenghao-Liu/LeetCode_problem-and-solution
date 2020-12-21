/*
 * dp[i][j]表示stones[i~j]区间情况下，当前玩家的最大得分差
 * 初始化，如果只有一个石头，那就没分，dp[i][i]=0
 * 状态转移：当前选择所获得的得分，减去选择之后对手能获得的得分，尽可能的得分差大
 * 因为最后是dp[0][size-1]，注意填表顺序，依赖于左下
 */
const int MAXN=1e3;
int dp[MAXN][MAXN];
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int stones_size=stones.size();
        //[i~j]= p[j+1]-p[i]
        vector<int> prefix(stones_size+1);
        for (int i=1;i<=stones_size;++i)
            prefix.at(i)=prefix.at(i-1)+stones.at(i-1);
        for (int j=0;j<stones_size;++j) {
            for (int i=j;i>=0;--i) {
                if (i==j) {
                    dp[i][j]=0;
                    continue;
                }
                int cho1=prefix.at(j)-prefix.at(i);
                int cho2=prefix.at(j+1)-prefix.at(i+1);
                dp[i][j]=max(cho1-dp[i][j-1],cho2-dp[i+1][j]);
            }
        }
        return dp[0][stones_size-1];
    }
};
