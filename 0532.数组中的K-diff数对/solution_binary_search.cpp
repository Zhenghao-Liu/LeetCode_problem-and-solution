/*
* 先排序且i<j即nums[i]<=nums[j]
* nums[j]-nums[i]>=0为非负数
  nums[j]-nums[i]==k
* 现在已i为处理单元，向右找nums[i]+k，且是有序的可以二分
* 这样子既不会重复，也不用担心k==0的情况
  若是以j为处理单元，向左找，无法考虑k==0情况
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k<0)
            return 0;
        sort(nums.begin(),nums.end());
        int ans=0;
        int nums_size=nums.size();
        for (int i=0;i<nums_size;++i)
        {
            if (i!=0 && nums.at(i)==nums.at(i-1))
                continue;
            auto p=lower_bound(nums.begin()+i+1,nums.end(),nums.at(i)+k);
            if (p!=nums.end() && *p==nums.at(i)+k)
                ++ans;
        }
        return ans;
    }
};
