/*
* 只需要从1到sqrt(num)范围枚举即可
* 因为如果有一个大于sqrt(num)的因数x，必然有一个小于sqrt(num)的因数num/x
* 所以求小于sqrt(num)的一半就可以同时求另一半
* 但是i==1时会额外增加一个num进入sum中，所以最后证明sum==num*2即可
*/
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num<=0)
            return false;
        int sum=0;
        for (int i=1;i*i<=num;++i)
        {
            if (num%i==0)
            {
                sum+=i;
                if (i*i!=num)
                    sum+=num/i;
            }
        }
        return sum==num*2;
    }
};
