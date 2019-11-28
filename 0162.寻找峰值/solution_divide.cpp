/*
* 评论区大神的分析
* nums[mid]<nums[mid+1]时，mid+1~N一定存在峰值
* 首先已知 nums[mid+1]>nums[mid]，
* 那么mid+2只有两种可能，一个是大于mid+1，一个是小于mid+1，
* 小于mid+1的情况，那么mid+1就是峰值，
* 大于mid+1的情况，继续向右推，如果一直到数组的末尾都是大于的，那么可以肯定最后一个元素是峰值，因为nums[nums.length]=负无穷
* 一句话，上坡的话要么还是上坡要么是坡顶
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left=0,right=nums.size()-1,mid;
        while (left<right)
        {
            mid=(left+right)/2;
            if (nums.at(mid)<nums.at(mid+1))
                left=mid+1;
            else
                right=mid;
        }
        return left;
    }
};
