/*
* 在解法2基础上
* 原地修改
* 内存复杂度优化为O(1)
*/
class Solution {
public:
int minimumTotal(vector<vector<int>>& triangle) 
{
	  int triangle_size=triangle.size();
	  if (triangle_size==0)
		return 0;
    for (int i=triangle_size-2;i>-1;--i)
        for (int j=0;j<=i;++j)
            triangle.at(i).at(j)=min(triangle.at(i+1).at(j),triangle.at(i+1).at(j+1))+triangle.at(i).at(j);
    return triangle.at(0).at(0);
}
};
