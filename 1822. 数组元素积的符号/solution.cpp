class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans=1;
        for (int i:nums) {
            if (i==0) {
                return 0;
            }
            ans*=i>0 ? 1 : -1;
        }
        return ans;
    }
};