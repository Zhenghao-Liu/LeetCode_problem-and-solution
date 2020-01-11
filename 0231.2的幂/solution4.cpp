//2次幂则2进制中只有1个1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && bitset<31>(n).count()==1;
    }
};
