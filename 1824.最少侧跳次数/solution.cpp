class Solution {
public:
    int minSideJumps(vector<int>& obs) {
        int sz=obs.size();
        vector<vector<int>> dp(3,vector<int>(sz,INT_MAX/2));
        dp.at(0).at(0)=dp.at(2).at(0)=1;
        dp.at(1).at(0)=0;
        for (int i=1;i<sz;i++) {
            int sto=obs.at(i);
            for (int j=0;j<3;j++) {
                if (sto-1==j) {
                    continue;
                }
                dp.at(j).at(i)=dp.at(j).at(i-1);
            }
            for (int j=0;j<3;j++) {
                if (sto-1==j) {
                    continue;
                }
                for (int k=0;k<3;k++) {
                    if (j==k || sto-1==k) {
                        continue;
                    }
                    dp.at(j).at(i)=min(dp.at(j).at(i),dp.at(k).at(i)+1);
                }
            }
            // cout << dp[0][i] << ' ' << dp[1][i] << ' ' << dp[2][i] << endl;
        }
        return min(dp.at(0).at(sz-1),min(dp.at(1).at(sz-1),dp.at(2).at(sz-1)));
    }
};