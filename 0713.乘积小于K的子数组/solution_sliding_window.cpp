//滑窗，固定左边界，移动右边界
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int nums_size=nums.size();
        int product=1;
        int r=0;
        for (int l=0;l<nums_size;++l)
        {
            if (r<l)
                r=l;
            while (product<k && r<nums_size)
            {
                product*=nums.at(r);
                ++r;
            }
            if (product<k)
                ans+=r-l;
            else if (r-l-1>0)
                ans+=r-l-1;
            product/=nums.at(l);
        }
        return ans;
    }
};
