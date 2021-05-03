typedef long long ll;
ll mod=1e9+7;
class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        ll ans=0;
        int sz=nums.size();
        for (int i=1;i<sz;i++) {
            int cur=nums.at(i);
            if (cur>target) {
                break;
            }
            int tar=target-cur;
            auto p=upper_bound(nums.begin(),nums.begin()+i,tar);
            ans+=p-nums.begin();
            ans%=mod;
        }
        return ans;
    }
};