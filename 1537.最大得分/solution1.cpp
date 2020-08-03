/*
* 显然只有遇到nums1和nums2都存在的值的位置时，才有讨论意义
* 可以想象成这些两个数组都有的元素值即重合点，重合点把nums1，nums2进行分段了
* 因为一到重合点，就有一个是否要切换到另一个数组的选择
  所以到达重合点后，比较nums1、nums2这两个数组被重合点分段后，该段的区间和大小，贪心的选择区间和更大的走即可
* 步骤：先求前缀和以求区间和
  通过双指针形式找到重合点，然后分段比较区间和大小
*/
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
