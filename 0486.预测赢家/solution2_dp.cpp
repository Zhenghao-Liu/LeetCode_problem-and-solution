/*
* dp(i, j) 表示当剩下的数为 nums[i .. j] 时，当前操作的选手（注意，不一定是先手）与另一位选手最多的分数差。当前操作的选手可以选择 nums[i] 并留下 nums[i+1 .. j]，或选择 nums[j] 并留下 nums[i .. j-1]
* dp(i, j) = max(nums[i] - dp(i+1, j), nums[j] - dp(i, j-1))
* dp(i, i) = nums[i]
* 如果 dp(0, n - 1) >= 0，那么先手必胜。
* dp[i+1][j]是下,dp[i][j-1]是左所以要先填左下角
* 该方向是从左到右的每一列，从下往上填
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int nums_size=nums.size();
        vector<vector<int>> dp(nums_size,vector<int>(nums_size));
        for (int i=0;i<nums_size;++i)
            dp.at(i).at(i)=nums.at(i);
        for (int j=1;j<nums_size;++j)
            for (int i=j-1;i>=0;--i)
                dp.at(i).at(j)=max(nums.at(i)-dp.at(i+1).at(j),nums.at(j)-dp.at(i).at(j-1));
        return dp.at(0).at(nums_size-1)>=0;
    }
};
