/*
* 采用自底向上
* 并且优化内存
*/
class Solution {
public:
int minimumTotal(vector<vector<int>>& triangle) 
{
	  int triangle_size=triangle.size();
	  if (triangle_size==0)
		return 0;
    int last_line_size=triangle.at(triangle_size-1).size();
    vector<int> dp(last_line_size);
    for (int i=0;i<last_line_size;++i)
        dp.at(i)=triangle.at(triangle_size-1).at(i);
    for (int i=triangle_size-2;i>-1;--i)
        for (int j=0;j<=i;++j)
            dp.at(j)=min(dp.at(j),dp.at(j+1))+triangle.at(i).at(j);
    return dp.at(0);
}
};
