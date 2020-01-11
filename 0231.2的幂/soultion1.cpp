class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long a=1;
        while (a<n)
            a=a<<1;
        return n==a;
    }
};
