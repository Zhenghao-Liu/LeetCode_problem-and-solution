class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prices_size=prices.size();
        if (prices_size==0)
            return 0;
        vector<vector<int>> dp(prices_size,vector<int>(2,0));
        dp.at(0).at(0)=0;
        dp.at(0).at(1)=-prices.at(0);
        for (int i=1;i<prices_size;++i)
        {
            dp.at(i).at(0)=max(dp.at(i-1).at(0),dp.at(i-1).at(1)+prices.at(i));
            if (i!=1)
                dp.at(i).at(1)=max(dp.at(i-1).at(1),dp.at(i-2).at(0)-prices.at(i));
            else
                dp.at(1).at(1)=max(dp.at(0).at(1),-prices.at(1));
        }
        return dp.at(prices_size-1).at(0);
    }
};
