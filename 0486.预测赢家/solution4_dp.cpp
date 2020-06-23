/*
* dp(i, j) 表示当剩下的数为 nums[i .. j] 时，当前操作的选手（注意，不一定是先手）与另一位选手最多的分数差。当前操作的选手可以选择 nums[i] 并留下 nums[i+1 .. j]，或选择 nums[j] 并留下 nums[i .. j-1]
* dp(i, j) = max(nums[i] - dp(i+1, j), nums[j] - dp(i, j-1))
* dp(i, i) = nums[i]
* 如果 dp(0, n - 1) >= 0，那么先手必胜。
* dp[i+1][j]是下,dp[i][j-1]是左所以要先填左下角
* 该方向是从底至上行，从左到右填
* 因为只与左下有关，可以压缩至一维
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int nums_size=nums.size();
        vector<int> dp=nums;
        for (int i=nums_size-1;i>=0;--i)
            for (int j=i+1;j<nums_size;++j)
                dp.at(j)=max(nums.at(i)-dp.at(j),nums.at(j)-dp.at(j-1));
        return dp.at(nums_size-1)>=0;
    }
};
