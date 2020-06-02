class Solution {
public:
    int hammingDistance(int x, int y) {
        return bitset<32>(x^y).count();
    }
};
