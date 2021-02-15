typedef long long ll;
ll mod=1e9+7;
class Solution {
public:
    int countHomogenous(string s) {
        int sz=s.size();
        ll ans=0;
        for (int i=0;i<sz;) {
            int j=i+1;
            for (;j<sz && s.at(j)==s.at(i);j++);
            ans+=solve(j-i);
            ans%=mod;
            i=j;
        }
        return ans;
    }
    ll solve(ll n) {
        return n*(1+n)/2%mod;
    }
};
