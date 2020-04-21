class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans=INT_MIN;
        int sum=0;
        for (int &i:nums)
        {
            sum+=i;
            ans=max(ans,1-sum);
        }
        return ans>0 ? ans : 1;
    }
};
