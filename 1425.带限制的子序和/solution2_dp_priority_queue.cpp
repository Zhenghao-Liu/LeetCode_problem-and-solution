/*
* dp[i]以i结尾为子序列的最大和，即该序列一定是有nums[i]的
* dp.at(i)=max(nums.at(i),dp.at(j)+nums.at(j)); i-j<=k i>j
* nums.at(i)即单独以[i]作为序列
* dp[j]+nums.at(j)即在最后两个数相邻情况下，可构成的所有可能组序列的和最大值
* 但是每一次都遍历一次所有可能的j有点太麻烦
* 用一个优先队列去维护dp[j]，那么最大值就在队头，且距离过远即i-j>k的要出队
*/
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int nums_size=nums.size();
        //以i结尾为子序列的最大和
        vector<int> dp(nums_size);
        dp.at(0)=nums.at(0);
        //first为dp[j]
        //second为j
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> helper;
        helper.push({nums.at(0),0});
        int ans=nums.at(0);
        for (int i=1;i<nums_size;++i)
        {
            while (!helper.empty() && i-helper.top().second>k)
                helper.pop();
            dp.at(i)=max(nums.at(i),helper.top().first+nums.at(i));
            helper.push({dp.at(i),i});
            ans=max(ans,dp.at(i));
        }
        return ans;
    }
};
