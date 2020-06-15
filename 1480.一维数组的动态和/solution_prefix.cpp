class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans=nums;
        for (int i=1;i<nums.size();++i)
            ans.at(i)+=ans.at(i-1);
        return ans;
    }
};
