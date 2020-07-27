class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int size=nums.size();
        for (int i=0;i<size;i+=2)
            ans+=nums.at(i);
        return ans;
    }
};
