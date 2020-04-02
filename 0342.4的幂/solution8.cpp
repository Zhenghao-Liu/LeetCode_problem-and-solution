/*
* n=4^x=(2^2)^x=2^k即k=2x，即要保证是2的幂且k是偶数才可以
* 对n进行模3处理，就可以判断出2的指数是奇数还是偶数
*/
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0 && (num&num-1)==0 && num%3==1;
    }
};
