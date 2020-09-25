#ifndef PERM_COMB
#define PERM_COMB

typedef long long ll;
ll mod=1e9+7;
const int MAXN=1001;

//$C_{n}^{m}$即comb[n][m]
//上面是m，下面是n
ll comb[MAXN][MAXN];
void build_comb(int limit)
{
    //memset(comb,0,sizeof(comb));
    for (int n=1;n<=limit;++n)
        for (int m=0;m<=n;++m)
        {
            if (m==n || m==0)
                comb[n][m]=1;
            else
                comb[n][m]=(comb[n-1][m]%mod+comb[n-1][m-1]%mod)%mod;
        }
}

//$C_{n}^{m}$即comb[n][m]
//上面是m，下面是n
ll get_comb(ll n,ll m) {
    ll ans=1;
    for(ll i=n;i>m;--i)
        ans*=i;
    for(ll i=n-m;i>0;--i)
        ans/=i;
    return ans%mod;
}

//$A_{n}^{m}$即perm[n][m]
//上面是m，下面是n
//perm[n][m]=comb[n][m]*m!
ll perm[MAXN][MAXN];
void build_perm(int limit)
{
    //memset(perm,0,sizeof(perm));
    for (int n=0;n<=limit;++n)
        for (int m=0;m<=n;++m)
        {
            if (m==0)
                perm[n][m]=1;
            else
                perm[n][m]=n*(perm[n-1][m-1])%mod;
        }
}

//$A_{n}^{m}$即perm[n][m]
//上面是m，下面是n
ll get_perm(ll n,ll m) {
    ll ans=1;
    for(ll i=n;i>n-m;--i)
    {
        ans*=i;
        ans%=mod;
    }
    return ans;
}

#endif