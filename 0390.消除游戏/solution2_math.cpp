/**
* [数学证明](https://blog.csdn.net/afei__/article/details/83689502)
* f(n)是序列从左到右的最终结果
* b(n)是序列从右到左的最终结果
* 当n=1时f(n)=b(n)=1
* 两个结论：f(n)+b(n)=n+1 归纳法证明
           f(n)=2*b(n/2) 因为[1 2 3 4 5]从左往右一次后[2 4]和2*[1 2]一个结果
* 最后可得：b(n)=n+1-f(n)=n+1-2*b(n/2)
         且b(n/2)=n/2+1-f(n/2)
         即f(n)=2*b(n/2)=2*(n/2+1-f(n/2))
*/
class Solution {
public:
    int lastRemaining(int n) {
        if (n==1)
            return 1;
        return 2*(n/2+1-lastRemaining(n/2));
    }
};
