/**
* 注意要求是非空，即至少要有一对乘积
* dp[i][j]表示以nums1[i]和nums2[j]为末尾的最大点积
* 那么对于nums1[i]和nums2[j]无非就是取和不取的问题
  1.不取nums1[i]则dp[i-1][j]
  2.不取nums2[j]则dp[i][j-1]
  取nums1[i]和nums2[j]，但是对于前面是取还是不取呢？
  又分了两种新的情况，即选且只选这两个数，和选两个数加上前面的情况
  3.选且只选这两个则nums1[i]*nums2[j]
  4.选两个且加上前面的情况dp[i-1][j-1]+nums1[i]*nums2[j]
  5.还有一种可能是两个都不选，直接选前面的情况即dp[i-1][j-1]
    但这个条件其实在1.2.都已经包含了，所以可写可不写
*/
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int nums1_size=nums1.size();
        int nums2_size=nums2.size();
        vector<vector<int>> dp(nums1_size,vector<int>(nums2_size,INT_MIN));
        for (int i=0;i<nums1_size;++i)
            for (int j=0;j<nums2_size;++j)
            {
                int temp=nums1.at(i)*nums2.at(j);
                if (i-1>=0)
                    temp=max(dp.at(i-1).at(j),temp);
                if (j-1>=0)
                    temp=max(dp.at(i).at(j-1),temp);
                if (i-1>=0 && j-1>=0)
                {
                    temp=max(dp.at(i-1).at(j-1),temp);
                    temp=max(dp.at(i-1).at(j-1)+nums1.at(i)*nums2.at(j),temp);
                }
                dp.at(i).at(j)=temp;
            }
        return dp.at(nums1_size-1).at(nums2_size-1);
    }
};
