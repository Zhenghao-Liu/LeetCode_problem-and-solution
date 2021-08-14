class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0;
        int ans=0;
        unordered_map<int,int> ump;
        ump[0]=1;
        for (int i:nums) {
            sum+=i;
            auto p=ump.find(sum-goal);
            if (p!=ump.end()) {
                ans+=p->second;
            }
            ump[sum]++;
        }
        return ans;
    }
};