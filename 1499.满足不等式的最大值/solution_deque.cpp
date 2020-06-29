/*
* yi+yj+|xi-xj|的最大值，且xi<xj总成立
* 即yi+yj+xj-xi最大值
* 那以j为处理单元，即求yj+xj-xi+yi的最大值
  即xj+yj-(xi-yi)最大值，现在j确定了，即求满足条件下，(xi-yi)的最小值
* 且要满足xj-xi<=k，则xi>=xj-k
* 代表要舍弃一部分xi，且只用知道xi-yi的最小值，那么应该用单调递增栈
* 当下j处理完后，即变成下一个j的i，压入队尾，因为是找(xi-yi)最小值
  所以队尾中second大于当前xi-yi的都应该出队
  所以要升级成双端队列
* 且一开始要出队不满足xj-xi<=k的情况
*/
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        //first存xi，second存xi-yi
        deque<pair<int,int>> helper;
        int ans=INT_MIN;
        for (vector<int> &i:points)
        {
            int xj=i.at(0);
            int yj=i.at(1);
            while (!helper.empty() && helper.front().first<xj-k)
                helper.pop_front();
            if (!helper.empty())
                ans=max(ans,xj+yj-helper.front().second);
            int second=xj-yj;
            while (!helper.empty() && helper.back().second>=second)
                helper.pop_back();
            helper.push_back({xj,second});
        }
        return ans;
    }
};
