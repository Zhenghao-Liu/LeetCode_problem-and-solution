class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums,0,S);
    }
    int dfs(vector<int> &nums,int index,int sum)
    {
        if (index==nums.size())
            return sum==0 ? 1 : 0;
        return dfs(nums,index+1,sum-nums.at(index))+dfs(nums,index+1,sum+nums.at(index));
    }
};
