class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN/2;
        int mi=0;
        int cur=0;
        for (int i:nums) {
            cur+=i;
            ans=max(ans,cur-mi);
            mi=min(mi,cur);
        }
        return ans;
    }
};