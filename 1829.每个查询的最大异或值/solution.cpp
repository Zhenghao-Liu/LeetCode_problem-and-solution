class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int tar=(1<<maximumBit)-1;
        int sz=nums.size();
        vector<int> ans(sz);
        int all=0;
        for (int i:nums) {
            all^=i;
        }
        for (int i=0;i<sz;i++) {
            ans.at(i)=tar^all;
            all^=nums.at(sz-1-i);
        }
        return ans;
    }
};