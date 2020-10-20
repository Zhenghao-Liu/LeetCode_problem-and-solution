/*
 * 乘法逆元
 * ( c / a ) % m = c * a^(-1) % m
 * 当m是个质数时：a^(-1) = a^(m-2) % m 
 * 本题可以假设原来的数是x，最终答案是Ax+B
   即只用记录整体的斜率A和截距B即可
 * 整体加inc即B+=inc
 * 整体乘m即(Ax+B)*m，即A*=m B*=m
 * 但是对于新添加元素怎么办呢？
   可以求逆的操作即新增加的是y，但我存的是x，满足Ax+B=y
 * 因此求x=(y-B)/A
   但是有个麻烦的点是要求余，(y-B)/A%mod
   所以要用到乘法逆元的知识变成
   (y-B)/A%mod = (y-B) * A^(-1) % mod = (y-B) * A^(mod-2) % mod
 */
typedef long long ll;
ll mod=1e9+7;
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
const int MAXN=100000;
ll x[MAXN];
class Fancy {
    //Ax+B
    int size=0;
    ll A=1,B=0;
public:
    Fancy() {
        memset(x,0,sizeof(x));
        size=0;
        A=1;
        B=0;
    }
    
    void append(int val) {
        ll ans=((val-B+mod)%mod) * (quick_pow2(A,mod-2)%mod) %mod;
        x[size]=ans;
        ++size;
    }
    
    void addAll(int inc) {
        B+=inc;
        B%=mod;
    }
    
    void multAll(int m) {
        A*=m;
        A%=mod;
        B*=m;
        B%=mod;
    }
    
    int getIndex(int idx) {
        if (idx>=size)
            return -1;
        ll ans=(A*x[idx]%mod+B)%mod;
        return (int)ans;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
