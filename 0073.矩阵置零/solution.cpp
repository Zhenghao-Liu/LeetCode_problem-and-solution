//O(m+n)
class Solution {
public:
void setZeroes(vector<vector<int>>& matrix)
{
	int row=matrix.size(),column=matrix.at(0).size();
	vector<vector<int>> zeros_place;
	for (int i=0;i<row;++i)
		for (int j=0;j<column;++j)
			if (matrix.at(i).at(j)==0)
				zeros_place.push_back(vector<int>({i,j}));
	int zeros_place_size=zeros_place.size(),zero_row,zero_column;
	for (int i=0;i<zeros_place_size;++i)
	{
		zero_row=zeros_place.at(i).at(0);
		zero_column=zeros_place.at(i).at(1);
		for (int j=0;j<row;++j)
			if (matrix.at(j).at(zero_column)!=0)
				matrix.at(j).at(zero_column)=0;
		for (int j=0;j<column;++j)
			if (matrix.at(zero_row).at(j)!=0)
				matrix.at(zero_row).at(j)=0;
	}
}
};
