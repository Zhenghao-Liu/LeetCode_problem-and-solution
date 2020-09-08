#ifndef QUICK_POW
#define QUICK_POW

#include<iostream>
using namespace std;

long long mod=1e9+7;
long long quick_pow1(long long a,long long n)
{
    //a^n
    if (n<0)
    {
        cerr << "error quick pow" << endl;
        return -1;
    }
    if (a==0)
        return 0;
    if (n==0)
        return 1;
    a%=mod;
    if ((n&1)==1)
        return a*quick_pow1(a,n-1)%mod;
    else
    {
        long long half=quick_pow1(a,n/2);
        return half*half%mod;
    }
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

#endif