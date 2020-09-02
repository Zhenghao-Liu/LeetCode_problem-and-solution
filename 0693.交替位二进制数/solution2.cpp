/*
* 如果是01交替，则n与n>>1的和是一个全1的数，那么再+1就是一个2的幂次
* 判断是否是2的幂次即可
*/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long sum=(long long)(n^(n>>1))+1;
        return (sum&(sum-1))==0;
    }
};
