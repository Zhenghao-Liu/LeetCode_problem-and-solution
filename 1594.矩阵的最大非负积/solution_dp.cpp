//因为有负数，所以要统计最大和最小
typedef long long ll;
class Solution {
    ll mod=1e9+7;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        ll r=grid.size();
        ll c=grid.at(0).size();
        vector<vector<ll>> dp_min(r,vector<ll>(c,INT_MAX/2));
        vector<vector<ll>> dp_max(r,vector<ll>(c,INT_MIN/2));
        dp_min.at(0).at(0)=dp_max.at(0).at(0)=grid.at(0).at(0);
        for (ll j=1;j<c;++j)
            dp_min.at(0).at(j)=dp_max.at(0).at(j)=dp_min.at(0).at(j-1)*grid.at(0).at(j);
        for (ll i=1;i<r;++i)
            dp_min.at(i).at(0)=dp_max.at(i).at(0)=dp_min.at(i-1).at(0)*grid.at(i).at(0);
        for (ll i=1;i<r;++i)
            for (ll j=1;j<c;++j)
            {
                ll n=grid.at(i).at(j);
                if (n==0)
                    dp_min.at(i).at(j)=dp_max.at(i).at(j)=0;
                else if (n<0)
                {
                    dp_min.at(i).at(j)=max(dp_max.at(i-1).at(j),dp_max.at(i).at(j-1))*n;
                    dp_max.at(i).at(j)=min(dp_min.at(i-1).at(j),dp_min.at(i).at(j-1))*n;
                }
                else
                {
                    dp_min.at(i).at(j)=min(dp_min.at(i-1).at(j),dp_min.at(i).at(j-1))*n;
                    dp_max.at(i).at(j)=max(dp_max.at(i-1).at(j),dp_max.at(i).at(j-1))*n;
                }
            }
        ll ans=dp_max.at(r-1).at(c-1);
        if (ans<0)
            return -1;
        return ans%mod;
    }
};
