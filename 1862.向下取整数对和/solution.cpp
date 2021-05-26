/*
 * d=x/y
 * 枚举y、d则x在 y*d<=x<y*(d+1)的区间内，即y*d<=x<=y*(d+1)-1
 */
typedef long long ll;
ll mod=1e9+7;
const int MAXN=1e5+1;
ll cnt[MAXN];
ll pre[MAXN+1];
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        memset(cnt,0,sizeof(cnt));
        memset(pre,0,sizeof(pre));
        for (int i:nums) {
            cnt[i]++;
        }
        for (int i=0;i<=mx;i++) {
            pre[i+1]=cnt[i]+pre[i];
        }
        ll ans=0;
        for (int y=1;y<=mx;y++) {
            if (cnt[y]==0) {
                continue;
            }
            ll res=0;
            for (int d=1;y*d<=mx;d++) {
                ll n=pre[min(mx,y*(d+1)-1)+1]-pre[y*d];
                res+=n*d%mod;
                res%=mod;
            }
            ans+=res*cnt[y]%mod;
            ans%=mod;
        }
        return ans;
    }
};