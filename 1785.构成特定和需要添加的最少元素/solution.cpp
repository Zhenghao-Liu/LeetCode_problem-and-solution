typedef long long ll;
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        ll sum=0;
        for (int i:nums) {
            sum+=i;
        }
        ll dec=goal-sum;
        if (dec==0) {
            return 0;
        } else if (dec>0) {
            ll t=dec%limit;
            ll ans=dec/limit;
            if (t!=0) {
                ans++;
            }
            return ans;
        }
        ll t=(dec)%(-limit);
        ll ans=dec/(-limit);
        if (t!=0) {
            ans++;
        }
        return ans;
    }
};
