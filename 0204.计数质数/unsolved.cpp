//常规做法，但运算量太大了所以运行超时了
class Solution {
public:
    int countPrimes(int n) {
        int answer=n>2?1:0;
        for (int i=3;i<n;i=i+2)
            if (is_prime_number(i))
                ++answer;
        return answer;
    }
    bool is_prime_number(int n)
    {
        /*
        if (n==2)
            return true;
        if (n<2 || n%2==0)
            return false;
        */
        for (int i=3;i<n/2;i=i+2)
            if (n%i==0)
                return false;
        return true;
    }
};
