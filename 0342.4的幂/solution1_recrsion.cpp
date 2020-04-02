class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num==1)
            return true;
        else if (num%4==0 && num!=0)
            return isPowerOfFour(num/4);
        return false;
    }
};
