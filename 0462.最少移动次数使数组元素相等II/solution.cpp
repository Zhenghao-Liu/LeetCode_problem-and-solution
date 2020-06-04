/**
* 所有数都变成中位数是最优解
* 当数组个数是偶数时，中位数应该是由中间两个决定，但是不应该出现小数的情况，所以选哪一个当基准都可以
*/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if (nums.size()<=1)
            return 0;
        sort(nums.begin(),nums.end());
        int sum=0;
        int key=nums.at(nums.size()/2);
        for (int &i:nums)
            sum+=abs(key-i);
        return sum;
    }
};
