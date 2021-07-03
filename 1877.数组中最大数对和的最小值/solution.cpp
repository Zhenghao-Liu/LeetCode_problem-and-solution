class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sz=nums.size();
        int ans=0;
        for (int i=0;i<sz/2;i++) {
            int a=nums.at(i),b=nums.at(sz-1-i);
            ans=max(ans,a+b);
        }
        return ans;
    }
};