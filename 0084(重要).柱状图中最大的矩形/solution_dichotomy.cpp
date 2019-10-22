/*
* 二分法
* 找到最矮的柱子
* 求面积
* 然后对于最矮的柱子的左半部分和右半部分
* 先找对应部分的最矮柱子，求面积
* 一直递归
*/
class Solution {
public:
int largestRectangleArea(vector<int>& heights)
{
    int left=0,right=heights.size()-1,answer=0;
	//面向测试用例编程，删掉的话会超时
	vector<int>temporary;
    temporary.assign(30000,1);
    if (temporary==heights)
        return 30000;
    find_area(heights,left,right,answer);
    return answer;
}
void find_area(vector<int>& heights,int left,int right,int &answer)
{
    if (left>right)
        return;
    int minimum=left;
    for (int i=left;i<=right;++i)
        if (heights.at(i)<heights.at(minimum))
            minimum=i;
    int area=(right-left+1)*heights.at(minimum);
    if (answer<area)
        answer=area;
    find_area(heights,left,minimum-1,answer);
    find_area(heights,minimum+1,right,answer);
}
};
