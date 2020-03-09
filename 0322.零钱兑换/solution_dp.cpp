//dp.at(i)=min(dp.at(i-coins[j])+1;经典背包问题
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp.at(0)=0;
        for (int i=1;i<=amount;++i)
        {
            int temp=INT_MAX;
            for (int &j:coins)
                if (i-j>=0)
                    temp=min(temp,dp.at(i-j));
            if (temp!=INT_MAX)
                dp.at(i)=temp+1;
        }
        return dp.at(amount)==INT_MAX ? -1 : dp.at(amount);
    }
};
