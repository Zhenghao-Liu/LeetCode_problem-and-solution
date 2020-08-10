//因为有负数的存在，则要么是最大的三个数相乘，要么是最小的两个数相乘后变成了正数再和最大的数相乘
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int nums_size=nums.size();
        int a=nums.at(0);
        int b=nums.at(1);
        int c=nums.at(nums_size-3);
        int d=nums.at(nums_size-2);
        int e=nums.at(nums_size-1);
        return max(a*b*e,c*d*e);
    }
};
