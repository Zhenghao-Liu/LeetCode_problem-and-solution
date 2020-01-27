class Solution {
public:
    bool isUgly(int num) {
        //因为负数的质因数中一定有-1，所以负数一定不是丑数，0也不是丑数
        if (num<1)
            return false;
        while (num%2==0)
            num=num>>1;
        while (num%3==0)
            num=num/3;
        while (num%5==0)
            num=num/5;
        return num==1;
    }
};
