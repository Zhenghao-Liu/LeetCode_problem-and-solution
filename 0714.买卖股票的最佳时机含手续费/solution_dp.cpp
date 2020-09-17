//dp[i][0]表示不持有股票，dp[i][1]表示持有股票
class Solution {
    int INFS=INT_MIN/2;
public:
    int maxProfit(vector<int>& prices, int fee) {
        int size=prices.size();
        vector<vector<int>> dp(size+1,vector<int>(2,0));
        dp[0][1]=INFS;
        int ans=0;
        for (int i=1;i<=size;++i)
        {
            int p=prices.at(i-1);
            dp.at(i).at(0)=max(dp.at(i-1).at(0),dp.at(i-1).at(1)+p-fee);
            dp.at(i).at(1)=max(dp.at(i-1).at(1),dp.at(i-1).at(0)-p);
        }
        return dp.at(size).at(0);
    }
};
