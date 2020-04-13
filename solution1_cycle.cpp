class Solution {
public:
    bool isPerfectSquare(int num) {
        //最大的平方数2147395600
        if (num==0 || num==2147395600)
            return true;
        int test=1;
        while (test<46340 && test*test<num)
            ++test;
        return test*test==num;
    }
};
