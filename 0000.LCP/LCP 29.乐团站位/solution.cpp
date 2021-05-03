typedef long long ll;
class Solution {
public:
    int orchestraLayout(ll n, ll x, ll y) {
        ll all=n*n;
        ll idx=INT_MAX;
        idx=min(idx,x-0+1);
        idx=min(idx,n-x);
        idx=min(idx,y-0+1);
        idx=min(idx,n-y);
        ll cur=0;
        cur+=(idx-1)*(4*n-4)-8*(idx-1)*(idx-2)/2;
        if (x==idx-1) {
            cur+=y-(idx-1)+1;
            return solve(cur);
        } else if (y==n-idx) {
            cur+=n-2*(idx-1);
            cur+=x-(idx-1);
            return solve(cur);
        } else if (x==n-idx) {
            cur+=n-2*(idx-1);
            cur+=n-2*(idx-1)-1;
            cur+=n-idx-y;
            return solve(cur);
        } else if (y==idx-1) {
            cur+=n-2*(idx-1);
            cur+=n-2*(idx-1)-1;
            cur+=n-2*(idx-1)-1;
            cur+=n-idx-x;
            return solve(cur);
        }
        return -1;
    }
    ll solve(ll a) {
        ll b=a%9;
        if (b!=0) {
            return b;
        }
        return 9;
    }
};

