class Solution {
public:
int maximalRectangle(vector<vector<char>>& matrix) 
{
	int row=matrix.size();
	if (row<1)
		return 0;
	int column=matrix.at(0).size(),answer=0,temporary;
	vector<int> heights(column,0);
	for (int i=0;i<row;++i)
	{
		for (int j=0;j<column;++j)
			if (matrix.at(i).at(j)=='0')
				heights.at(j)=0;
			else
				heights.at(j)=heights.at(j)+1;
		temporary=largestRectangleArea(heights);
		if (temporary>answer)
			answer=temporary;
	}
	return answer;
}
int largestRectangleArea(vector<int>& heights)
{
    int heights_size=heights.size();
	stack<int> stack_heights;
	stack_heights.push(-1);
    stack_heights.push(0);
	int temporary,temporary_top,answer=0;
	for (int i=1;i<heights_size;++i)
		if (heights.at(i)>heights.at(i-1))
			stack_heights.push(i);
		else
		{
			while(stack_heights.top()!=-1 && heights.at(i)<=heights.at(stack_heights.top()))
			{
				temporary_top=stack_heights.top();
				stack_heights.pop();
				temporary=heights.at(temporary_top)*(i-stack_heights.top()-1);
				if (temporary>answer)
					answer=temporary;
			}
			stack_heights.push(i);
		}	
	int after_loop_top=stack_heights.top();
	while (stack_heights.top()!=-1)
	{
		temporary_top=stack_heights.top();
		stack_heights.pop();
		temporary=heights.at(temporary_top)*(after_loop_top-stack_heights.top());
		if (temporary>answer)
			answer=temporary;
	}
    return answer;
}
};
