typedef long long ll;
ll mod=1e9+7;
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<ll,ll> ump;
        ll ans=0;
        for (int i:nums) {
            ll tar=i-rev(i);
            auto p=ump.find(tar);
            if (p!=ump.end()) {
                ans+=p->second;
                ans%=mod;
            }
            ump[tar]++;
        }
        return ans;
    }
    int rev(int a) {
        int ans=0;
        while (a!=0) {
            ans=ans*10+(a%10);
            a/=10;
        }
        return ans;
    }
};