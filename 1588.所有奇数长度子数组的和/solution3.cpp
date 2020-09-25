/*
* odd奇数，even偶数
* 对于每个元素i(数组中下标为i)来说，要构成奇数长度的子数组
  即 i左边的元素个数left+i本身自己一个+右边元素的个数right=奇数
  即 left+right=偶数
* 满足a+b=偶数就只有两种情况
  1. 奇数+奇数=偶数
  2. 偶数+偶数=偶数
* 1. 所以只需要求得i左边可以选择奇数长度的可能有多少种，即left_odd,同样求右边奇数right_odd
     就可以求出策略1有多少种可能
  2. 所以只需要求得i左边可以选择偶数长度的可能有多少种，即left_odd,同样求右边偶数right_odd
     就可以求出策略1有多少种可能，注意0也算选择的一种可能
* 即元素i在所有奇数长度子数组出现的次数总和是
  left_odd*right_odd+left_even*right_even
* 元素i左边元素共有i个，右边元素共有siz-i-1个
*/
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int siz=arr.size();
        int ans=0;
        for (int i=0;i<siz;++i)
        {
            int left=i,right=siz-i-1;
            int left_odd=(left+1)/2,right_odd=(right+1)/2;
            int left_even=left/2+1,right_even=right/2+1;
            ans+=(left_odd*right_odd+left_even*right_even)*arr.at(i);
        }  
        return ans;
    }
};
