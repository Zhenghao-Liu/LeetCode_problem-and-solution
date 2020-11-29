class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for (vector<int> &i:accounts)
        {
            int sum=0;
            for (int j:i)
                sum+=j;
            ans=max(ans,sum);
        }
        return ans;
    }
};
