/*
* 利用单调栈,从左到右遍历，栈中存取位置而不是值
* 当height[i]大于栈顶s.top()时，表明此时出现了低谷，举个例子3 0 2，栈顶是0的位置，第二个元素是3的位置，而[i]代表2，意味着要往里面接水
  即取出栈顶元素0作为低边lower，取[i]和栈顶下一个元素即3的最小值来作为高边upper，再取距离distance，即可求出该低谷要接水的容量
* 当height[i]小于栈顶时，表明需要找到一个高的右边来构成一个低谷，所以入栈即可
*/
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int height_size=height.size();
        int ans=0;
        for (int i=0;i<height_size;++i)
        {
            while (!s.empty() && height.at(i)>height.at(s.top()))
            {
                int lower=height.at(s.top());
                s.pop();
                if (s.empty())
                    break;
                int upper=min(height.at(i),height.at(s.top()));
                int distance=i-s.top()-1;
                ans+=(upper-lower)*distance;
            }
            s.push(i);
        }
        return ans;
    }
};
