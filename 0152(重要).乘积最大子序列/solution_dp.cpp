/*
* 因为负数的存在，不仅要记录最小值还要记录最大值，因为负数乘最小值就变成了最大值
* 当奇数个负数时，part_min表示乘积最小子序列
* 当偶数个负数时，part_max表示乘积最大子序列
* 当第i为负数时，假设前面已经有奇数个负数，加上i则有偶数个负数，则最大值为part_min*i，所以遇到负数时，进行交换part_min、part_max
* 以0为分割，但遇到0不用特殊处理因为part_min、part_max都会置零
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int answer=INT_MIN,part_max=1,part_min=1;
        for (int &i:nums)
        {
            if (i<0)
                swap(part_max,part_min);
            part_max=max(part_max*i,i);
            part_min=min(part_min*i,i);
            if (part_max>answer)
                answer=part_max;
        }
        return answer;
    }
};
