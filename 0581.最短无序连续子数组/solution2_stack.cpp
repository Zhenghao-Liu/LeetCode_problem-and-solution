/*
* 首先向左到右遍历维护一个递增的单调栈，栈中存nums的索引
* 如果一个数组是已经排好序的，那么自然栈中就一直单调递增
  倘若出现nums[i]<stack.top()时，表明出现无序区间
  则出栈，知道满足单调栈，并且求得最短无序连续子数组的左区间
* 同样反过来从右到左维护一个递减的单调炸
  类似于上述操作，求得右区间
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> s;
        int nums_size=nums.size();
        int left=nums_size;
        for (int i=0;i<nums_size;++i)
        {
            while (!s.empty() && nums.at(i)<nums.at(s.top()))
            {
                left=min(left,s.top());
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty())
            s.pop();
        int right=left;
        for (int i=nums_size-1;i>=left;--i)
        {
            while (!s.empty() && nums.at(i)>nums.at(s.top()))
            {
                right=max(right,s.top()+1);
                s.pop();
            }
            s.push(i);
        }
        return right-left;
    }
};
