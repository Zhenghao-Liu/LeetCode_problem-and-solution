class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sz=nums.size();
        return nums.at(sz-1)*nums.at(sz-2)-nums.at(0)*nums.at(1);
    }
};