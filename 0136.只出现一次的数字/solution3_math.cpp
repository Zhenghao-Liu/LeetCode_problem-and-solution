/*
* [a,a,b,b,c]
* c=(a+b+c)*2-(a+a+b+b+c)
* 即：出现一次的数字=集合的和*2-所有数字的和
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> nums_set;
        int sum=0;
        for (int i:nums)
        {
            sum=sum+i;
            nums_set.insert(i);
        }
        int sum_set=0;
        for (int i:nums_set)
            sum_set=sum_set+i;
        return 2*sum_set-sum;
    }
};
