//求和法：通过n(a1+an)/2来求和，a1=0，an=nums.size()，n=nums.size()+1，求和减去当前数组求和即没有出现的数字
//但在数组过大超过65536长度时(通过a1n+n(n-1)d/2=2^31求解)，求合法会有溢出
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for (int &i:nums)
            sum=sum+i;
        return (nums.size()*(nums.size()+1))/2-sum;
    }
};
