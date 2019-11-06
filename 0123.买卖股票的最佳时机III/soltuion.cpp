class Solution {
public:
int maxProfit(vector<int>& prices) {
    int prices_size=prices.size();
	if (prices_size<2)
		return 0;
	vector<vector<int>> dp (2,vector<int>(prices_size,0));
	int min;
	if (prices.at(1)>prices.at(0))
	{
		min=prices.at(0);
		dp.at(0).at(1)=prices.at(1)-prices.at(0);
	}
	else
		min=prices.at(1);
	for (int i=2;i<prices_size;++i)
	{
		if (prices.at(i)==0 && prices.at(i-1)==0)
			dp.at(0).at(i)=dp.at(0).at(i-1);
		else
			dp.at(0).at(i)=max(dp.at(0).at(i-1),prices.at(i)-min);
		if (prices.at(i)<min)
			min=prices.at(i);
	}
	for (int i=1;i<prices_size;++i)
	{
		if (prices.at(i)==0 && prices.at(i-1)==0)
			dp.at(1).at(i)=dp.at(1).at(i-1);
		else
		{
			for (int j=0;j<i;++j)
				dp.at(1).at(i)=max(dp.at(1).at(i),prices.at(i)-prices.at(j)+dp.at(0).at(j));
			dp.at(1).at(i)=max(dp.at(1).at(i-1),dp.at(1).at(i));
		}	
	}
	return dp.at(1).at(prices_size-1);
}
};
