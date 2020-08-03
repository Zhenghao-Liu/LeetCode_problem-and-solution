//整体思路同solution1，但既然双指针时候也要遍历一次nums1、nums2，可以在找重合点同时求区间和
class Solution {
    long long mod=1e9+7;
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int nums1_size=nums1.size();
        int nums2_size=nums2.size();
        long long a=0,b=0;
        int i=0,j=0;
        long long ans=0;
        while (i<nums1_size && j<nums2_size)
        {
            if (nums1.at(i)==nums2.at(j))
            {
                a+=nums1.at(i);
                b+=nums2.at(j);
                ans+=max(a,b);
                ans%=mod;
                ++i;
                ++j;
                a=b=0;
            }
            else if (nums1.at(i)<nums2.at(j))
            {
                a+=nums1.at(i);
                ++i;
            }
            else
            {
                b+=nums2.at(j);
                ++j;
            }
        }
        while (i<nums1_size)
        {
            a+=nums1.at(i);
            ++i;
        }
        while (j<nums2_size)
        {
            b+=nums2.at(j);
            ++j;
        }
        ans+=max(a,b);
        ans%=mod;
        return ans;
    }
};
