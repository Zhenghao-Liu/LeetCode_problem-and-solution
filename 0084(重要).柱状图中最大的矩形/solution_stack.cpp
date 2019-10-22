/*
* 神奇的栈。。看题解把。想不到
*/
class Solution {
public:
int largestRectangleArea(vector<int>& heights)
{
    int heights_size=heights.size();
	stack<int> stack_heights;
	stack_heights.push(-1);
    if (heights_size==0)
        return 0;
    else
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
