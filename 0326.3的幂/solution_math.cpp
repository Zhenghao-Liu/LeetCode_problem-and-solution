/*
* int最大值INT_MAX=2147483647
* log3(2147483648)=19.558
* 那么3的幂次方最大值就是3^19=1162261467
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0) && (1162261467 % n == 0);
    }
};
