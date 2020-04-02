//x=4^a 则a=log4(x)=0.5*log2(x)为整数，即log2(x)要为2的倍数才能除2后为整数
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        return num>0 and log2(num)%2==0
