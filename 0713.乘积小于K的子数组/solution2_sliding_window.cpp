//滑窗，固定右边界，移动左边界
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k<=1)
            return 0;
        int ans=0;
        int nums_size=nums.size();
        int product=1;
        int l=0;
        for (int r=0;r<nums_size;++r)
        {
            product*=nums.at(r);
            while (product>=k)
            {
                product/=nums.at(l);
                ++l;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
};
