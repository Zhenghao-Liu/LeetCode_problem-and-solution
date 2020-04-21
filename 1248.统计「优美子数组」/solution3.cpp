//设key为奇数的个数，value为出现某奇数个数组合的个数
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> prefix_count(nums.size()+1);
        prefix_count.at(0)=1;
        int sum=0,ans=0;
        for (int &i:nums)
        {
            sum+=i&1;
            ++prefix_count.at(sum);
            if (sum>=k)
                ans+=prefix_count.at(sum-k);
        }
        return ans;
    }
};
