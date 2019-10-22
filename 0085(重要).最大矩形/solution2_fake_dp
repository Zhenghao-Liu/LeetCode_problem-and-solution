class Solution {
public:
int find_its_Rectangle_include_itself(vector<vector<char>>& matrix,const int& i,const int &j)
{
	int minimum_long=INT_MAX,answer=0;
	int temporary_i=i,temporary_j=j;
	while (temporary_i>-1 && temporary_j>-1 && matrix.at(temporary_i).at(temporary_j)=='1')
	{
		int k=temporary_j,temporary_long=0;
		while (k>-1 && matrix.at(temporary_i).at(k)=='1')
		{
			++temporary_long;
			--k;
		}
		if (temporary_long<minimum_long)
			minimum_long=temporary_long;
		--temporary_i;
		int temporary_area=(i-temporary_i)*minimum_long;
		if (answer<temporary_area)
			answer=(i-temporary_i)*minimum_long;
	}
	return answer;
}
int maximalRectangle(vector<vector<char>>& matrix) 
{
	int row=matrix.size();
	if (row<1)
		return 0;
	int column=matrix.at(0).size();
	vector<vector<int>> dp(row,vector<int>(column,0));
	if (matrix.at(0).at(0)=='1')
		dp.at(0).at(0)=1;
	else
		dp.at(0).at(0)=0;
	int temporary_long=dp.at(0).at(0);
	for (int i=1;i<column;++i)
		if (matrix.at(0).at(i)=='1')
		{
			++temporary_long;
			if (matrix.at(0).at(i-1)=='1')
				dp.at(0).at(i)=max(temporary_long,dp.at(0).at(i-1));
			else
				dp.at(0).at(i)=max(1,dp.at(0).at(i-1));
		}	
		else
		{
			temporary_long=0;
			dp.at(0).at(i)=dp.at(0).at(i-1);
		}	
	temporary_long=dp.at(0).at(0);
	for (int i=1;i<row;++i)
		if (matrix.at(i).at(0)=='1')
		{
			++temporary_long;
			if (matrix.at(i-1).at(0)=='1')
				dp.at(i).at(0)=max(temporary_long,dp.at(i-1).at(0));
			else
				dp.at(i).at(0)=max(1,dp.at(i-1).at(0));
		}	
		else
		{
			temporary_long=0;
			dp.at(i).at(0)=dp.at(i-1).at(0);
		}
	for (int i=1;i<row;++i)
		for (int j=1;j<column;++j)
			if (matrix.at(i).at(j)=='0')
				dp.at(i).at(j)=max(dp.at(i-1).at(j),dp.at(i).at(j-1));
			else
				dp.at(i).at(j)=max(dp.at(i-1).at(j),max(dp.at(i).at(j-1),find_its_Rectangle_include_itself(matrix,i,j)));
	return dp.at(row-1).at(column-1);
}
};
