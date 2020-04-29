class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int nums_size=nums.size();
        //以i结尾为子序列的最大和
        vector<int> dp(nums_size);
        dp.at(0)=nums.at(0);
        for (int j=1;j<nums_size;++j)
        {
            dp.at(j)=nums.at(j);
            for (int i=j-1;j-i<=k && i>=0;--i)
                dp.at(j)=max(dp.at(j),dp.at(i)+nums.at(j));
        }
        int ans=INT_MIN;
        for (int &i:dp)
            if (i>ans)
                ans=i;
        return ans;
    }
};
