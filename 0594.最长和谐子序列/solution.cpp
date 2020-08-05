//既然是子序列，且要求最大值最小值差正好是1，那么对于数i，只需要找到i-1出现了几次和i+1出现了几次即可
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> count;
        for (int i:nums)
        {
            ++count[i];
            int t=0;
            if (count.find(i-1)!=count.end() && count.at(i-1)>t)
                t=count.at(i-1);
            if (count.find(i+1)!=count.end() && count.at(i+1)>t)
                t=count.at(i+1);
            if (t!=0)
                ans=max(ans,count.at(i)+t);
        }
        return ans;
    }
};
