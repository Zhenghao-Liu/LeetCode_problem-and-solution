/*
* 暴力解法
* 对所有连续子集求一次面积
* 超时
*/
class Solution {
public:
int largestRectangleArea(vector<int>& heights)
{
    int heights_size=heights.size(),area=0,temporary;
	vector<int>::iterator minimum;
    for (int i=0;i<heights_size;++i)
		for (int j=i;j<heights_size;++j)
		{
			minimum=min_element(heights.begin()+i,heights.begin()+j+1);
			temporary=*minimum*(j-i+1);
			if (temporary>area)
				area=temporary;
		}
    return area;
}
};
