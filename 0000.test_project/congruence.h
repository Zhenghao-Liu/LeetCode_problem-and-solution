#ifndef CONGRUENCE
#define CONGRUENCE

typedef long long ll;

/*
 * 操作a与b，且结果对mod求余
 * add : (a+b)%mod = (a%mod+b%mod)%mod
 * sub : (a-b)%mod = (a%mod-b%mod+mod)%mod
 * mul : (a*b)%mod = (a%mod)*(b%mod)%mod
 * div : (a/b)%mod = a*(b^(-1))%mod
   若mod为一个质数，则有 x^(-1)%mod=x^(mod-2)%mod，次方操作需要采用快速幂
   div ：(a/b)%mod = (a%mod)*(b^(mod-2)%mod)%mod
 */

long long quick_pow2_2(ll a,ll n,ll mod)
{
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

ll add_mod(ll a,ll b,ll mod)
{
    return (a%mod+b%mod)%mod;
}

ll sub_mod(ll a,ll b,ll mod)
{
    return (a%mod-b%mod+mod)%mod;
}

ll mul_mod(ll a,ll b,ll mod)
{
    return (a%mod)*(b%mod)%mod;
}

ll div_mod(ll a,ll b,ll mod)
{
    //mod必须为质数
    return (a%mod)*quick_pow2_2(b,mod-2,mod)%mod;
}
#endif