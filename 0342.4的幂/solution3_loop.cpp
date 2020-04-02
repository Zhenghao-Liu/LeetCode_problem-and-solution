class Solution {
public:
    bool isPowerOfFour(int num) {
        long long a=1;
        while (a<num)
            a<<=2;
        return a==num;
    }
};
