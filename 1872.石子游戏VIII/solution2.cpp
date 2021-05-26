/*
 * 思路二：dp[i]表示对第i个石头开始拿的考虑（同样前缀和处理stones）
 * dp[i]=max(pre[i]-dp[i+1],
             pre[i+1]-dp[i+2],
             ···,
             pre[sz-1])
 * 而 pre[i+1]-dp[i+2],pre[i+2]-dp[i+3],···,pre[sz-1] 不就是 dp[i+1]
 * 所以 dp[i]=max(pre[i]-dp[i+1],dp[i+1])
 */
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int sz=stones.size();
        for (int i=1;i<sz;i++) {
            stones.at(i)+=stones.at(i-1);
        }
        vector<int> dp(sz,INT_MIN/2);
        dp.at(sz-1)=stones.at(sz-1);
        for (int i=sz-2;i>=1;i--) {
            dp.at(i)=max(dp.at(i+1),stones.at(i)-dp.at(i+1));
        }
        return dp.at(1);
    }
};