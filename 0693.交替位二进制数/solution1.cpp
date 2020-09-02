/*
* 如果是01交替，那么n与n>>1的和是一个二进制下全1的数
* 通过hightbit求这个全1的数
*/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long sum=(highbit(n)<<1)-1;
        return (long long)n+(n>>1)==sum;
    }
    long long lowbit(int x)
    {
        return x&(-x);
    }
    long long int highbit(int x)
    {
        long long p=lowbit(x);
        while (p!=x)
        {
            x-=p;
            p=lowbit(x);
        }
        return p;
    }
};
