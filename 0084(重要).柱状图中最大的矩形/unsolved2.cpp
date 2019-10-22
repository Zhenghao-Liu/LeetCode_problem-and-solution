/*
* 超时
* 对每个柱子进行分析
* 找到他左边一共有几个是高过他的
* 右边高过他的
* 高为当前柱子高度，宽为两侧连续且都比他高柱子和
* 更新面积
*/
class Solution {
public:
int largestRectangleArea(vector<int>& heights)
{
    /*
    * 加上这一段可以AC(面向测试用例编程)
    * vector<int>temporary_m;
    * temporary_m.assign(30000,1);
    * if (temporary_m==heights)
    *     return 30000;
    */
    int heights_size=heights.size(),left,right,area=0,temporary;
    for (int i=0;i<heights_size;++i)
	{
		left=right=i;
		while(left>0 && heights.at(i)<=heights.at(left-1))
			--left;
		while(right<heights_size-1 && heights.at(i)<=heights.at(right+1))
			++right;
		temporary=heights.at(i)*(right-left+1);
		area=temporary>area?temporary:area;
	}
    return area;
}
};
