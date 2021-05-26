/*
 * 最少要拿两个石头
 * 拿了石头之后会放一个等价值的石头，等价于可选范围向右缩，石头不变
   所以可以用一个前缀和去维护石头的价值，这里偷懒用了stones直接维护
 * dp[i]表示从第i个石头开始考虑的最大价值
 * 初始化：全部拿完，也就是dp[sz-1]==stones数组的和
 * 对于第i个石头，有拿和不拿两种情况
 * 如果拿，获得的价值就是前缀和stones[i]，那么对手就会从i+1这个位置开始考虑
   分差就是： 前缀和stones[i]-dp[i+1]
 * 如果不拿，则从下一个石头开始考虑
   也就是：dp[i+1]
 * 选取最优max(拿，不拿)
 * 最后返回dp[1]，因为最少拿两块石头，则必须从[1]石头开始考虑
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