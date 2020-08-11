/*
* 把问题转化成：从 kk 个列表中各取一个数，使得这 kk 个数中的最大值与最小值的差最小
* 那么维护一个多指针数组指向当前处理的每个列表的处理元素的位置
* 用堆来维护当前指向元素中的最小值，同时维护当前求得区间的最大值
* 不断更新最小值和最大值，比较差，直到某一个指针指向列表的end为止
*/
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int ans_l=-1e5,ans_r=1e5;
        int nums_size=nums.size();
        vector<int> p(nums_size,0);
        auto cmp=[&nums,&p](const int &A,const int &B){
            return nums.at(A).at(p.at(A))>nums.at(B).at(p.at(B));
        };
        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
        int cur_max=INT_MIN;
        for (int i=0;i<nums_size;++i)
        {
            pq.push(i);
            cur_max=max(cur_max,nums.at(i).at(0));
        }
        while (true)
        {
            int cur_min_p=pq.top();
            pq.pop();
            int cur_min=nums.at(cur_min_p).at(p.at(cur_min_p));
            if (cur_max-cur_min<ans_r-ans_l)
            {
                ans_l=cur_min;
                ans_r=cur_max;
            }
            ++p.at(cur_min_p);
            if (p.at(cur_min_p)==(int)nums.at(cur_min_p).size())
                break;
            cur_max=max(cur_max,nums.at(cur_min_p).at(p.at(cur_min_p)));
            pq.push(cur_min_p);
        }
        return {ans_l,ans_r};
    }
};
