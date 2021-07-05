typedef long long ll;
ll mod=1e9+7;
class Solution {
public:
    int countGoodNumbers(long long n) {
        ll half=n/2;
        return quick_pow2(4,half)*quick_pow2(5,n-half)%mod;
    }
    long long quick_pow2(long long a,long long n)
    {
        if (n<0)
        {
            cerr << "error quick pow" << endl;
            return -1;
        }
        if (a==0)
            return 0;
        a%=mod;
        long long ans=1;
        while (n!=0)
        {
            if ((n&1)==1)
            {
                ans*=a;
                ans%=mod;
            }
            a*=a;
            a%=mod;
            n>>=1;
        }
        return ans;
    }
};