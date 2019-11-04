class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prices_size=prices.size();
        if (prices_size<2)
            return 0;
        vector<int> dp(prices_size);
        dp.at(0)=0;
        int min;
        if (prices.at(1)>prices.at(0))
        {
            min=prices.at(0);
            dp.at(1)=prices.at(1)-prices.at(0);
        } 
        else
        {
            min=prices.at(1);
            dp.at(1)=0;
        }  
        for (int i=2;i<prices_size;++i)
        {
            dp.at(i)=max(dp.at(i-1),prices.at(i)-min);
            if (prices.at(i)<min)
                min=prices.at(i);
        }
        return dp.at(prices_size-1);
    }
};
