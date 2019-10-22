class Solution {
public:
vector<vector<int>> generateMatrix(int n)
{
	vector<vector<int>> answer(n,vector<int>(n));
	int lower_limit=0,upper_limit=n,index=1,position_x=0,position_y=-1;
	int times=(n+1)/2;
	for (int i=0;i<times;++i)
	{
		while(position_y<upper_limit-1)
		{
			++position_y;
			answer.at(position_x).at(position_y)=index++;
		}
		while(position_x<upper_limit-1)
		{
			++position_x;
			answer.at(position_x).at(position_y)=index++;
		}
		while(position_y>lower_limit)
		{
			--position_y;
			answer.at(position_x).at(position_y)=index++;
		}
		while(position_x>lower_limit+1)
		{
			--position_x;
			answer.at(position_x).at(position_y)=index++;
		}
		++lower_limit;
		--upper_limit;
	}
	return answer; 
}
};
