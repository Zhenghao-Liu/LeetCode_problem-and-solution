class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int sz=nums.size();
        vector<int> ans(sz);
        for (int i=0;i<sz;i++) {
            ans.at(i)=nums.at(nums.at(i));
        }
        return ans;
    }
};