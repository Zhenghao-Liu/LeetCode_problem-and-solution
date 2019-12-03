/*
* 出现最多的元素占这个数组一半以上
* 那么排序后这个出现的元素要么占前半段或以上者占后半段以上
* 以上两种情况则出现最多的元素都必然出现在中间位置
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums.at(nums.size()/2);
    }
};
