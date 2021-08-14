typedef long long ll;
const ll MISS=INT_MAX+1;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ll cur=0;
        int cnt=0;
        for (int i:nums) {
            if (cnt==0) {
                cur=i;
                cnt=1;
                continue;
            }
            if (i==cur) {
                cnt++;
            } else {
                cnt--;
            }
        }
        if (cnt==0) {
            return -1;
        }
        cnt=0;
        for (int i:nums) {
            if (i==cur) {
                cnt++;
            }
        }
        int sz=nums.size();
        return cnt>sz/2 ? cur : -1;
    }
};