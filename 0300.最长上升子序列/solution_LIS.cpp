/*
* 因为要上升的的长，自然是希望上升的慢，即序列中最后加上的数字尽可能小
* last_num_in_lis[i]指长度为i的序列的末尾元素的最小值
  len表示当前序列长度
* 初始化len=1 last_num_in_lis[1]=nums.at(0)
* last_num_in_lis[i]必然是一个单调递增的序列
  证明：假设j<i 且last[j]>=last[i]，那么对于i来说删掉部分数字(i-j个)变成和j一样长的序列，且序列本身就是上升子序列，则last[i-(i-j)]<last[i]即与假设不符合，证明是单调递增
* 对于nums[i]>last[len]，表明可以构成更长的上升子序列则 ++len; last[len]=nums[i]
* 对于nums[i]<last[len]，此时已经有len来记录当前序列最长长度，且万一后面有更小的数字比当前末尾数字要小且可以构成更长的序列时，我们要更新
  eg:[1,2,5,3,4]对于i=2时last为{1,2,5} len=3，但后面可能有更小的数字但是可以构成更长的上升序列，我们可以更新数字，而且这个更新对当前长度不影响
  我们要找到位置x，即last[x]>=nums[i] 且last[x-1]<num，更新last[x]=num[i]，且last数组是个单调递增，就可以用二分来降低复杂度
  eg:[1,2,5,3,4]对于i=3时nums[3]=3，last{1,2,5}，即5是>=3 且2<3 则更新5这个位置为3
* 最后返回len即可
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==0)
            return 0;
        int len=1;
        vector<int> last_num_in_LIS(nums_size+1);
        last_num_in_LIS.at(1)=nums.at(0);
        for (int i=1;i<nums_size;++i)
            if (nums.at(i)>last_num_in_LIS.at(len))
            {
                ++len;
                last_num_in_LIS.at(len)=nums.at(i);
            }
            else if (nums.at(i)<last_num_in_LIS.at(len))
            {
                int left=1,right=len;
                while (left<right)
                {
                    int mid=left+((right-left)>>1);
                    if (last_num_in_LIS.at(mid)>=nums.at(i))
                        right=mid;
                    else
                        left=mid+1;
                }
                last_num_in_LIS.at(right)=nums.at(i);
            }
        return len;
    }
};
