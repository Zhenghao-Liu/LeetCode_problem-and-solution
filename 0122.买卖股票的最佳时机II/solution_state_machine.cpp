/*
* [状态机题解](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/)
* dp[i][k][s]
* i表示第几天0<=i<=n-1
* k表示最多交易次数1<=k<=K
* s取值0或1，表示有无持有股票，1有0无
* dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
* dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
* 浓缩
* 因为k为正无穷，所以k=k-1即dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k][0]-prices[i])
* 因为k永远为k，所以浓缩成二维数组
* 注意边界即i=0的情况
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n<2)
            return 0;
        vector<vector<int>> dp(n,vector<int>(2));
        dp.at(0).at(0)=0;
        dp.at(0).at(1)=-prices.at(0);
        for (int i=1;i<n;++i)
        {
            dp.at(i).at(0)=max(dp.at(i-1).at(0),dp.at(i-1).at(1)+prices.at(i));
            dp.at(i).at(1)=max(dp.at(i-1).at(1),dp.at(i-1).at(0)-prices.at(i));
        }
        return dp.at(n-1).at(0);
    }
};
