//n=4^a 则 a=log4(n)为整数
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num<=0)
            return false;
        int n=log(num)/log(4);
        return n*log(4)==log(num);
    }
};
