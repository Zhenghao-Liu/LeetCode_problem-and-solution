/*
* 参考powacai算法
* 比如2^{10} = {2^2}^5 = 4^5 = 4 ×{4^4} = 4 × 8^2 = ....
* 可以通过不断缩小指数,来降低复杂度.
* 作者：powcai
* 链接：https://leetcode-cn.com/problems/powx-n/solution/bei-jiang-zhi-shu-by-powcai/
*/

class Solution {
public:
    double myPow(double x, int n) 
    {
        if (n < 0)  
            if (n==INT_MIN)
                return 1.0/x* myPow(1.0/x,-1*(n+1));
            else
                return myPow(1.0/x,-n);
        if (n==0) return 1;
        if (n%2==0)
            return myPow(x*x,n/2);
        else
            return x*myPow(x*x,n/2);
    }
};
