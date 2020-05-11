class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int &i:nums)
            sum+=i;
        if (sum%2==1)
            return false;
        int target=sum/2;
        int nums_size=nums.size();
        //dp[i][j]表示nums中[0]~[i]可否选出子元素构成和为j的情况
        vector<vector<bool>> dp(nums_size,vector<bool>(target+1,false));
        for (int i=0;i<nums_size;++i)
            dp.at(i).at(0)=true;
        if (nums.at(0)<=target)
            dp.at(0).at(nums.at(0))=true;
        for (int i=1;i<nums_size;++i)
        {
            for (int j=1;j<=target;++j)
            {
                if (j-nums.at(i)>=0)
                    dp.at(i).at(j)=dp.at(i-1).at(j) || dp.at(i-1).at(j-nums.at(i));
                else
                    dp.at(i).at(j)=dp.at(i-1).at(j);
            }
            //相比于solution2多了这个剪枝
            //因为我们只要能够和达到target=sum/2就行，不用管在哪个区间
            if (dp.at(i).at(target))
                return true;
        }
        return dp.at(nums_size-1).at(target);
    }
};
