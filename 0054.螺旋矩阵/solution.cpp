class Solution {
public:
vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    if(matrix.empty())
		return {};
	int matrix_row_size=matrix.size(),matrix_column_size=matrix.at(0).size();
	vector<int> answer;
	int loop_times=(min(matrix_row_size,matrix_column_size)+1)/2,row=0,column=-1;
	int boundary_row_right=matrix_column_size,boundary_column_down=matrix_row_size;
	int boundary_row_left=0,boundary_column_up=0;
	for (int i=0;i<loop_times;++i)
	{
		while(column<boundary_row_right-1)
			answer.push_back(matrix.at(row).at(++column));
		while(row<boundary_column_down-1)
			answer.push_back(matrix.at(++row).at(column));
		while(column>boundary_row_left)
			answer.push_back(matrix.at(row).at(--column));
		while(row>boundary_column_up+1)
			answer.push_back(matrix.at(--row).at(column));
		--boundary_row_right;
		--boundary_column_down;
		++boundary_row_left;
		++boundary_column_up;
	}
	if (answer.size()!=matrix_row_size*matrix_column_size)
		if (matrix_row_size>matrix_column_size)
			for (int i=matrix_row_size-matrix_column_size-1;i>0;--i)
				answer.pop_back();
		else if (matrix_row_size<matrix_column_size)
			for (int i=matrix_column_size-matrix_row_size;i>0;--i)
				answer.pop_back();
	return answer;
}
};
