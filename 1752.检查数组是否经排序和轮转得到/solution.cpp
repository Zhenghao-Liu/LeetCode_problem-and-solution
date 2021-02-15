class Solution {
public:
    bool check(vector<int>& nums) {
        int sz=nums.size();
        if (check(nums,0,sz-1)) {
            return true;
        }
        for (int i=0;i<sz-1;i++) {
            if (check(nums,0,i) && check(nums,i+1,sz-1) && nums.at(sz-1)<=nums.at(0)) {
                return true;
            }
        }
        return false;
    }
    bool check(vector<int> &nums,int l,int r) {
        for (int i=l+1;i<=r;i++) {
            if (nums.at(i)<nums.at(i-1)) {
                return false;
            }
        }
        return true;
    }
};
