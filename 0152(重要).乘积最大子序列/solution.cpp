/*
* 以0为分界成一段一段分析
* 在一段中负数的个数要么为偶数要么为奇数
* 倘若负数的个数为偶数，那么直接相乘必然是最大值，因为偶数个负数相乘为正数
* 倘若负数有奇数个，设为n个的话，那么n-1个负数则为偶数个
* 那么这个减一因为是连续的子序列，所以要么是不包含最左边的负数，要么是不包含最右边的负数，只有这两种情况
* 那么只需要从左往右遍历一次，从右往左遍历一次，求最大值就可以了
* 注意为0的时候，虽然product要设置回1，但是有可能最大值就是0(每段都只有1个负数)，那么需要判断下answer是否更新为0
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int nums_size=nums.size(),product=1,answer=INT_MIN;
        for (int i=0;i<nums_size;++i)
        {
            if (nums.at(i)==0)
            {
                product=1;
                if (0>answer)
                    answer=0;
                continue;
            }
            product=product*nums.at(i);
            if (product>answer)
                answer=product;
        }
        product=1;
        for (int i=nums_size-1;i>=0;--i)
        {
            if (nums.at(i)==0)
            {
                product=1;
                if (0>answer)
                    answer=0;
                continue;
            }
            product=product*nums.at(i);
            if (product>answer)
                answer=product;
        }
        return answer;
    }
};
