/*
* 先转置
* 然后根据中心列进行对称交换
*/
class Solution {
public:
void rotate(vector<vector<int>> &matrix)
{
	int matrix_size=matrix.size();
	if (matrix_size<=1)
		return;
	for (int i=0;i<matrix_size;++i)
		for (int j=i+1;j<matrix_size;++j)
			swap(matrix.at(i).at(j),matrix.at(j).at(i));
	for (int i=0;i<matrix_size/2;++i)
		for (int j=0;j<matrix_size;++j)
			swap(matrix.at(j).at(i),matrix.at(j).at(matrix_size-i-1));
}
};
