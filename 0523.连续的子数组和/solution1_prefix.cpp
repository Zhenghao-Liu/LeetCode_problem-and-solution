//前缀和求所有子数组和的情况
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int nums_size=nums.size();
        if (nums_size<2)
            return false;
        vector<int> prefix(nums_size);
        prefix.at(0)=nums.at(0);
        for (int i=1;i<nums_size;++i)
            prefix.at(i)=prefix.at(i-1)+nums.at(i);
        for (int i=0;i<nums_size;++i)
            for (int j=nums_size-1;j-i+1>=2;--j)
            {
                int sum;
                if (i-1>=0)
                    sum=prefix.at(j)-prefix.at(i-1);
                else
                    sum=prefix.at(j);
                if ((sum==0 && k==0) || (k!=0 && sum%k==0))
                    return true;
            }
        return false;
    }
};
