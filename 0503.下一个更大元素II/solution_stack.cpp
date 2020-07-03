/**
* 假设不是循环数组，只是单纯求每个元素右边第一个比该元素大的数
  采用单调递增栈
* 但本题是循环数组，不仅要考虑右边，还要考虑左边情况
* 不如直接将nums复制一份加在原nums后面
* 这样对于新nums求出的后半部分单调栈，就求了元素左边的情况
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int nums_size=nums.size();
        vector<int> ans(nums_size,-1);
        nums.insert(nums.end(),nums.begin(),nums.end());
        stack<int> monotone_inc;
        for (int i=2*nums_size-1;i>=nums_size;--i)
        {
            while (!monotone_inc.empty() && monotone_inc.top()<=nums.at(i))
                monotone_inc.pop();
            monotone_inc.push(nums.at(i));
        }
        for (int i=nums_size-1;i>=0;--i)
        {
            while (!monotone_inc.empty() && monotone_inc.top()<=nums.at(i))
                monotone_inc.pop();
            if (!monotone_inc.empty())
                ans.at(i)=monotone_inc.top();
            monotone_inc.push(nums.at(i));
        }
        return ans;
    }
};
