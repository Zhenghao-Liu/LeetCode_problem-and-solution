typedef long long ll;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        ll ans=0;
        ll a=0,b=0;
        int sz=nums.size();
        for (int i=0;i<sz;) {
            int cur=nums.at(i);
            int j=i+1;
            for (;j<sz;j++) {
                if (nums.at(j-1)<=nums.at(j)) {
                    break;
                }
            }
            if (j==sz) {
                ans+=cur;
                i=j;
                continue;
            }
            if (j==i+1) {
                i=j;
                continue;
            }
            ans+=cur-nums.at(j-1);
            i=j;
        }
        return ans;
    }
};