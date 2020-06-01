/*
* 长度为n
* 当前未处理时数组元素总和为sum
* 设最终需要移动m次
* 那么由于每次移动n-1个元素加1，移动m次
  即总共增加了(n-1)*m
* 假设最后所有元素相等时单个元素是x
* 那么x*n=sum+(n-1)*m
* 对于当前未处理元素来说
  讨论最小值min_val，因为他通过移动m次变成了x
  即min_val+m=x
* 代入上式子几时(min_val+m)*n=sum+(n-1)*m
  化简得m=sum-min_val*n
*/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==0)
            return 0;
        long long sum=0;
        int min_val=INT_MAX;
        for (int &i:nums)
        {
            sum+=i;
            if (i<min_val)
                min_val=i;
        }
        return sum-(long long)min_val*nums_size;
    }
};
