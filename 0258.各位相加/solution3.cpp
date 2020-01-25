/*
* s1=abc=100*a+10*b+c=99*a+9*b+(a+b+c)
* 经过一次数位相加后得s2=a+b+c
* 差值s1-s2=99*a+9*b，差值可以被9整除
* s2=a+b+c=de=10*d+e=9*d+(d+e)
* 再经过一次数位相加得s3=d+e
* 差值s2-s1=9*d，差值可以被9整除
* 可得每一次循环都是减小了9的倍数
* 当num小于9则num即答案
* num大于9时则表明还没循环完
* num=9因为此时已经是一位数了，所以不需要继续循环到0，返回9
*/
class Solution {
public:
    int addDigits(int num) {
        if (num>9)
        {
            num=num%9;
            if (num==0)
                return 9; 
        }
        return num;
    }
};
