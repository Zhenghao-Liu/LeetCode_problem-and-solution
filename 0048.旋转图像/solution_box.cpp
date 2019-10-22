/*
* 暴力破解法
* 把一个矩阵分成一个一个正方形来讨论，每个位置都只需要转3次即可，然后演算出规律即可
* 速度较快
*/
class Solution {
public:
void rotate(vector<vector<int>>& matrix) 
{
    int matrix_size=matrix.size();
	if (matrix_size<=1)
		return;
	int box_rotate_times=matrix_size-1;
	for (int i=0;i<matrix_size/2;++i)
	{
		for (int j=i;j<box_rotate_times;++j)
		{
			swap(matrix.at(i).at(j),matrix.at(box_rotate_times-j+i).at(i));
			swap(matrix.at(box_rotate_times-j+i).at(i),matrix.at(box_rotate_times).at(box_rotate_times-j+i));
			swap(matrix.at(box_rotate_times).at(box_rotate_times-j+i),matrix.at(j).at(box_rotate_times));
		}
		--box_rotate_times;
	}	
}
};
