//既然是4的幂，则(2^2)^n,即num^(0.5)仍是整数且是2的幂
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num<=0)
            return false;
        int temp=sqrt(num);
        if (sqrt(double(num))==temp)
            num=temp;
        else
            return false;
        return (num&num-1)==0;
    }
};
