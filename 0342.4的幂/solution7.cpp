/*
* 首先确保是2的幂，其次二进制下是100、10000、1000000···即有偶数个0
* 那我们用10101010 10101010 10101010 10101010B即0xaaaaaaaa来与num相与则结果为0
* 但是这个数已经超过INT_MAX了，所以最开始2位改成00就不超了即0x2aaaaaaa即715827882
*/
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0 && (num&num-1)==0 && (num&715827882)==0;
    }
};
