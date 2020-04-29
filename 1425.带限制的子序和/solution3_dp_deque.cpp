/*
* dp[i]以i结尾为子序列的最大和，即该序列一定是有nums[i]的
* dp.at(i)=max(nums.at(i),dp.at(j)+nums.at(j)); i-j<=k i>j
* nums.at(i)即单独以[i]作为序列
* dp[j]+nums.at(j)即在最后两个数相邻情况下，可构成的所有可能组序列的和最大值
* 但是每一次都遍历一次所有可能的j有点太麻烦
* 用一个优先队列去维护dp[j]，那么最大值就在队头，且距离过远即i-j>k的要出队
* 或者采用更优的双端队列来存dp[j]的索引j，比较处理用dp[j]
* [类似于239.滑动窗口最大值 的双端队列做法]](https://leetcode-cn.com/problems/sliding-window-maximum/solution/bao-li-multisetdequedp-by-lzh_yves/)
* 维护一个单调递减的双端队列，这样队头就是符合题意范围的j中最大的dp[j]
* 倘若此时要入队一个很大的元素，那么双端队列中比该元素小的都没有意义，因为要取的是最大值，那就把前面比该入队元素小的全部出队
* 还要注意左边界要i-j<=k
*/
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int nums_size=nums.size();
        //以i结尾为子序列的最大和
        vector<int> dp(nums_size);
        dp.at(0)=nums.at(0);
        deque<int> helper;
        helper.push_back(0);
        int ans=nums.at(0);
        for (int i=1;i<nums_size;++i)
        {
            if (i-helper.front()>k)
                helper.pop_front();
            dp.at(i)=max(nums.at(i),dp.at(helper.front())+nums.at(i));
            while (!helper.empty() && dp.at(i)>dp.at(helper.back()))
                helper.pop_back();
            helper.push_back(i);
            ans=max(ans,dp.at(i));
        }
        return ans;
    }
};
