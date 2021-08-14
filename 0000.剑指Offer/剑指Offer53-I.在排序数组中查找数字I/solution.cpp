class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans=0;
        for (int i:nums) {
            if (i==target) {
                ans++;
            }
        }
        return ans;
    }
};