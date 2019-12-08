/*
* [状态机题解](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/)
* dp[i][k][s]
* i表示第几天0<=i<=n-1
* k表示最多交易次数1<=k<=K,此题k=2
* s取值0或1，表示有无持有股票，1有0无
* dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
* dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
* 注意边界即i=0的情况
* dp[-1][k][0]=0 未开始时利润为0
* dp[-1][k][1]=负无穷 未开始时不可能有股票，既不可能事件
* dp[i][0][0]=0 不让买卖则利润为0
* dp[i][0][1]=负无穷 不让买卖则不可能有股票，即不可能事件
*/
class Solution {
public:
int maxProfit(vector<int>& prices) {
	int n=prices.size();
	if (n<2)
		return 0;
	vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2)));
	for (int i=0;i<n;++i)
	{
		dp.at(i).at(0).at(0)=0;
		dp.at(i).at(0).at(1)=INT_MIN;
		for (int k=1;k<3;++k)
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
    return dp.at(n-1).at(2).at(0);
}
};
