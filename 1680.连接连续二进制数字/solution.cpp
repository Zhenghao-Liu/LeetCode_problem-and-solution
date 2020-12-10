typedef long long ll;
ll mod=1e9+7;
class Solution {
public:
    int concatenatedBinary(int n) {
        ll ans=0;
        for (int i=1;i<=n;++i)
        {
            int len=32-__builtin_clz(i);
            ans=((ans<<len)+i)%mod;
        }
        return ans;
    }
};
