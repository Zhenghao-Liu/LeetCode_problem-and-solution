class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> ump;
        for (int i:nums) {
            ump[i]++;
        }
        int ans=0;
        for (auto &i:ump) {
            if (i.second==1) {
                ans+=i.first;
            }
        }
        return ans;
    }
};
