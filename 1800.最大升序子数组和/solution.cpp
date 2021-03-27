class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=0;
        int sz=nums.size();
        for (int i=0;i<sz;) {
            int cur=nums.at(i);
            int j;
            for (j=i+1;j<sz && nums.at(j)>nums.at(j-1);j++) {
                cur+=nums.at(j);
            }
            i=j;
            ans=max(ans,cur);
        }
        return ans;
    }
};