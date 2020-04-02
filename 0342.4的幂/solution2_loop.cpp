class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num==0)
            return false;
        while (num%4==0)
            num>>=2;
        return num==1;
    }
};
