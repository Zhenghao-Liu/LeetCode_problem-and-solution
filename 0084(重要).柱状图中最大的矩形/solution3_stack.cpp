//用单调递增栈
//遇到比栈顶要矮的柱子时，则一个一个出栈
//即栈顶为当前上边界，左边界为栈顶的下一个元素+1(有可能栈内不连续的情况)
//右边界即i-1
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        int ans=0;
        stack<int> helper;
        //为了存着左边界0
        //和方法二区别就是在栈中存-1，代表最左边界，即栈只有-1时其实就是方法二的栈空
        helper.push(-1);
        //以防柱子是个升序柱子，一直没有弹出
        heights.push_back(0);
        int heights_size=heights.size();
        for (int i=0;i<heights_size;++i)
        {
            while (helper.top()!=-1 && heights.at(i)<heights.at(helper.top()))
            {
                int cur_height=heights.at(helper.top());
                helper.pop();
                int right=i-1;
                //因为开头存了一个-1，所以一定不会栈空
                //存入了一个-1，所以有效柱子索引是以0为开头的
                int left=helper.top()+1;
                ans=max(ans,cur_height*(right-left+1));
            }
            helper.push(i);
        }
        return ans;
    }
};
