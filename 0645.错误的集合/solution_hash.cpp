//自身哈希，出现过的数字i则设置[i]的数为负数，这样若遇到[i]已经负数则说明i是重复数字，且没有被设为负数的则是丢失的数字
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int repeat_num=0;
        for (int i:nums)
        {
            i=abs(i);
            if (nums.at(i-1)<0)
                repeat_num=i;
            else
                nums.at(i-1)=-nums.at(i-1);
        }
        int nums_size=nums.size();
        int lost_num=0;
        for (int i=0;i<nums_size;++i)
            if (nums.at(i)>0)
                lost_num=i+1;
        return {repeat_num,lost_num};
    }
};
