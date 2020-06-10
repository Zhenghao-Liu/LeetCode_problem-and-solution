//一个数和它的补数之和必然是一个全为1的数，eg:101 + 010 =111，所以找到最高位然后求出这个和sum，再减去num即可，注意溢出的可能
class Solution {
public:
    int findComplement(int num) {
        int highbit=int(log2(num))+1;
        int sum=(unsigned int)(1<<highbit)-1;
        return sum-num;
    }
};
