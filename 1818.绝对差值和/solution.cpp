typedef long long ll;
ll mod=1e9+7;
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec(nums1);
        sort(vec.begin(),vec.end());
        int mx=INT_MIN;
        int sz=nums1.size();
        int res=0;
        ll sum=0;
        for (int i=0;i<sz;i++) {
            int diff=abs(nums1.at(i)-nums2.at(i));
            sum+=diff;
            sum%=mod;
            auto p=lower_bound(vec.begin(),vec.end(),nums2.at(i));
            if (p!=vec.end()) {
                int cur=abs((*p)-nums2.at(i));
                res=min(res,cur-diff);
                
            }
            if (p!=vec.begin()) {
                p--;
                int cur=abs((*p)-nums2.at(i));
                res=min(res,cur-diff);
            }
        }
        // cout << sum;
        sum=(sum+res+mod)%mod;
        return sum;
    }
};