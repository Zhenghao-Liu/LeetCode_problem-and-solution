class Solution {
public:
    int rob(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==0)
            return 0;
        else if (nums_size==1)
            return nums.at(0);
        else if (nums_size==2)
            return max(nums.at(0),nums.at(1));
        vector<int> dp(nums_size);
        dp.at(0)=nums.at(0);
        dp.at(1)=max(nums.at(0),nums.at(1));
        for (int i=2;i<nums_size;++i)
            dp.at(i)=max(dp.at(i-1),dp.at(i-2)+nums.at(i));
        return dp.at(nums_size-1);
    }
};
