//模拟a^2+b^2=c中的a与b
class Solution {
public:
    bool judgeSquareSum(int c) {
        int original_i=(int)sqrt(c);
        int pow_i=original_i*original_i;
        int j=c-original_i*original_i;
        for (int i=original_i;i>=0 && j<=pow_i;--i)
        {
            j=c-i*i;
            int sqrt_j=(int)sqrt(j);
            if (sqrt_j*sqrt_j==j)
                return true;
        }
        return false;
    }
};
