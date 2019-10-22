/*先找出最大的索引k满足nums[k] < nums[k+1],如果不存在,就翻转整个数组,结束;
再找出另一个大于K且为最大的l，满足nums[k] < nums[l];
交换nums[l]和nums[k];
最后翻转nums[k+1:]
举个例子:
比如nums = [1,2,7,4,3,1],下一个排列是什么?
找到第一个最大索引是nums[1] = 2
再找到第二个最大索引是nums[5] = 3
交换,nums = [1,3,7,4,2,1];
翻转,nums = [1,3,1,2,4,7]*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size<=1)
            return;
        int k=-1;
        for (int i=nums_size-2;i>=0;--i)
            if (nums.at(i)<nums.at(i+1))
            {
                k=i;
                break;
            }
        if (k==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int l;
        for (l=nums_size-1;l>k+1;--l)
            if (nums.at(l)>nums.at(k))
                break;
        swap(nums.at(k),nums.at(l));
        reverse(nums.begin()+k+1,nums.end());
    }
};
