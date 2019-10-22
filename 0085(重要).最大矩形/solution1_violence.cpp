class Solution {
public:
int maximalRectangle(vector<vector<char>>& matrix) 
{
	int row=matrix.size();
	if (row<1)
		return 0;
	int column=matrix.at(0).size(),answer=0,minimum_long;
	for (int i=0;i<row;++i)
		for (int j=0;j<column;++j)
			if (matrix.at(i).at(j)=='1')
			{
				minimum_long=INT_MAX;
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
			}
    return answer;
}
};
