//普通暴力O(n^2)dp
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        int envelopes_size=envelopes.size();
        if (envelopes_size==0)
            return 0;
        vector<int> dp(envelopes_size,1);
        int ans=1;
        for (int i=1;i<envelopes_size;++i)
        {
            for (int j=0;j<i;++j)
                if (envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1] && dp[j]+1>dp[i])
                    dp[i]=dp[j]+1;
            if (dp[i]>ans)
                ans=dp[i];
        }
        return ans;
    }
};
