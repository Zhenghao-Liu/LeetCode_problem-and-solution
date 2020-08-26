/*
* 首先乘2肯定比加1的增加更快
* 且最终变成大数的a，在乘2的过程中可以带着小数一起乘
* 所以先单独统计每个数加1的次数，
  其次因为最大的数可以带着小数一起乘2，所以只用统计最多用了几次乘2的数即可
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int max_count=0;
        for (int i:nums)
        {
            int count=-1;
            while (i>0)
            {
                ans+=i&1;
                i/=2;
                ++count;
            }
            max_count=max(count,max_count);
        }
        return ans+max_count;
    }
};
