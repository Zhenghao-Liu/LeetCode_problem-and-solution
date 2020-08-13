/*
* 1. a+b+c+d正确序列
* 2. b+b+c+d数据错误后的序列
* 3. b+c+d数据错误序列，去除重复值后
* 式子2-式子3苛求repeat_num
* 式子1-式子3可求lost_num
*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int nums_size=nums.size();
        int A=nums_size*(nums_size+1)/2;
        int B=0;
        for (int i:nums)
            B+=i;
        int C=0;
        unordered_set<int> helper(nums.begin(),nums.end());
        for (int i:helper)
            C+=i;
        return {B-C,A-C};
    }
};
