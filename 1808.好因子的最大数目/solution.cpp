typedef long long ll;
ll mod=1e9+7;
class Solution {
public:
    int maxNiceDivisors(int p) {
        if (p<=3) {
            return p;
        }
        ll A=p/3;
        ll B=p%3;
        ll a=A,b=0;
        if (B==1) {
            a--;
            b=2;
        } else if (B==2) {
            b=1;
        }
        ll ans=quick_pow2(3,a);
        for (int i=0;i<b;i++) {
            ans*=2;
            ans%=mod;
        }
        return ans;
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