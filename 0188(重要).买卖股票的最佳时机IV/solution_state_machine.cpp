//一次交易由买入和卖出构成，至少需要两天。所以说有效的限制 k 应该不超过 n/2，如果超过，就没有约束作用了，相当于 k = +infinity。这种情况是之前解决过的。
//一定要看题解和个人笔记
class Solution {
public:
int maxProfit(vector<int>& prices) {
    int prices_size=prices.size();
    int answer=0;
    for (int i=1;i<prices_size;++i)
        if (prices.at(i)>prices.at(i-1))
            answer=answer+prices.at(i)-prices.at(i-1);
    return answer;
}
int maxProfit(int k, vector<int>& prices) {
    int n=prices.size();
    if (n<2)
        return 0;
    int K=k;
    if (K>n/2)
        return maxProfit(prices);
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(K+1,vector<int>(2)));
    for (int i=0;i<n;++i)
    {
        dp.at(i).at(0).at(0)=0;
        dp.at(i).at(0).at(1)=INT_MIN;
        for (int k=1;k<=K;++k)
        {
            if (i==0)
            {
                dp.at(0).at(k).at(0)=0;
                dp.at(0).at(k).at(1)=-prices.at(0);
                continue;
            }
            dp.at(i).at(k).at(0)=max(dp.at(i-1).at(k).at(0),dp.at(i-1).at(k).at(1)+prices.at(i));
            if (dp.at(i-1).at(k-1).at(0)!=INT_MIN)
                dp.at(i).at(k).at(1)=max(dp.at(i-1).at(k).at(1),dp.at(i-1).at(k-1).at(0)-prices.at(i));
            else
                dp.at(i).at(k).at(1)=max(dp.at(i-1).at(k).at(1),INT_MIN);
        }
    }
    return dp.at(n-1).at(K).at(0);
}
};
