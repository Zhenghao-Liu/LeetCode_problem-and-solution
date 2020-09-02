/*
* interval_and[i]表示nums[i]~nums[i+k-1]的区间和，即长度为k的子数组
  用滑动数组即可求得
* 我们设a,b,c满足a<b<c
  他们是最终答案{a,b,c}
  即最终区间分为
  1. a代表nums[a]~nums[a+k-1]
  2. b代表nums[b]~nums[b+k-1]
  3. c代表nums[c]~nums[c+k-1]
  且之间不能重叠
  即a+k-1<b且b+k-1<c且c+k-1<nums_size
** 我们只需要固定b，那么就已经确定了nums[b]~nums[b+k-1]的区间和
  b的范围是k~nums_size-2k
  然后在左边0~b-k的范围内找到最大区间和的首索引a即可
  然后在右边b+k~nums_size-1的范围内找到最大区间和的首索引c即可
* 那么怎么找a呢，因为范围是0~b-k，可以从右往右遍历
  以dp形式，存储最大区间和长度为k的子数组，的首索引，设为left
* 同样找c，可以从右往左遍历
  同样以dp形式设为right
* 且题目要求返回字典序最小的索引
  对于求left，则区间和相等也不更新dp
  对于求right，区间和相等时要更新dp
*/
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int nums_size=nums.size();
        vector<int> interval_and(nums_size);
        for (int i=0;i<k;++i)
            interval_and.at(0)+=nums.at(i);
        for (int i=1;i+k-1<nums_size;++i)
            interval_and.at(i)=interval_and.at(i-1)-nums.at(i-1)+nums.at(i+k-1);
        vector<int> left(nums_size);
        left.at(0)=0;
        for (int i=1;i+k-1<nums_size;++i)
        {
            if (interval_and.at(i)>interval_and.at(left.at(i-1)))
                left.at(i)=i;
            else
                left.at(i)=left.at(i-1);
        }
        vector<int> right(nums_size);
        right.at(nums_size-k)=nums_size-k;
        for (int i=nums_size-k-1;i>=0;--i)
        {
            if (interval_and.at(i)>=interval_and.at(right.at(i+1)))
                right.at(i)=i;
            else
                right.at(i)=right.at(i+1);
        }
        int ans_sum=0;
        vector<int> ans; 
        ans.reserve(3);
        for (int b=k;b<=nums_size-2*k;++b)
        {
            int sum=0;
            sum+=interval_and.at(left.at(b-k));
            sum+=interval_and.at(b);
            sum+=interval_and.at(right.at(b+k));
            if (sum>ans_sum)
            {
                ans_sum=sum;
                ans.clear();
                ans.push_back(left.at(b-k));
                ans.push_back(b);
                ans.push_back(right.at(b+k));
            }
        }
        return ans;
    }
};
