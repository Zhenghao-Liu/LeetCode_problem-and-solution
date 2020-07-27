/*
* 求子数组的和，因为是连续的就想到了前缀和
* prefix[j]-prefix[i-1]=sum就可以求出所有子数组的和
* 现在要让和是奇数，那么即prefix[j]-prefix[i-1]的结果是奇数
* 偶-偶=偶
  偶-奇=奇
  奇-偶=奇
  奇-奇=偶
* 即满足 偶-奇=奇 奇-偶=奇 这两种情况就能构成子数组和是奇数情况
  所以prefix[j]作为被减数，然后通过odd、even统计prefix[i-1]中有几个奇数有几个偶数，即可
*/
class Solution {
    int mod=1e9+7;
public:
    int numOfSubarrays(vector<int>& arr) {
        long long ans=0;
        //奇数
        int odd=0;
        //偶数
        int even=1;
        int prefix=0;
        int size=arr.size();
        for (int i=0;i<size;++i)
        {
            prefix+=arr.at(i);
            if (prefix%2==0)
            {
                ans+=odd;
                ans%=mod;
                ++even;
            }
            else
            {
                ans+=even;
                ans%=mod;
                ++odd;
            }
        }
        return ans;
    }
};
