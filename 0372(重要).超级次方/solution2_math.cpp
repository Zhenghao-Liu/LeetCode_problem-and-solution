/*
* 在solution1的递归基础上，有无可优化my_pow O(n)的呢
* a^n=a*a^(n-1) 当n为奇数时
  a^n=(a^(n/2))^2 当n为偶数时
* 偶数时的缩小级别直接可以减半，优化很大
* 但仍记得(a*b)%k=(a%k)(b%k)%k
*/
class Solution {
private:
    const int base=1337;
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty())
            return 1;
        if (a==0)
            return 0;
        int last=b.back();
        b.pop_back();
        int left=my_pow(a,last);
        int right=my_pow(superPow(a,b),10);
        return (left*right)%base;
    }
    int my_pow(int a,int n)
    {
        if (n==0)
            return 1;
        if (n==1)
            return a%base;
        a%=base;
        if (n&1==1)
            return a*my_pow(a,n-1)%base;
        else
        {
            int half=my_pow(a,n/2);
            return half*half%base;
        }
    }
};
