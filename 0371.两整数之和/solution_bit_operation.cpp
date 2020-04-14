/*
* 198+33=231其实可以划分成进位数和不进位之和198+33=121+110
* 异或^即对应a+b的没有进位之和
* 进位和其实就是(a&b)<<1，因为个位数的进位是十位，以此类推，所以要左移一位
* 注意负数的存储方式是补码，当为负数时第一位标志位为1，会报错（有时候左移可能会剔除掉标志位造成奇怪错误）
  这里将int变成unsigned int，即将标志位变成普通数据位一样对待，不是0正1负，就不会报错
* 倘若进位不是0，代表还是要相加的，怎么办呢，再调用一次自己即可
*/
class Solution {
public:
    int getSum(int a, int b) {
        int sum=a^b;
        int carry=((unsigned int)a&b)<<1;
        if (carry!=0)
            return getSum(sum,carry);
        return sum; 
    }
};
