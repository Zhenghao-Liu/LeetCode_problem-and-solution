/**
* 滑窗找到所有和为目标值的可能子数组
* 但题目要求互不重叠，且是最小值，所以要存长度和上一个子数组的右边界
* 因为题目说了所有数都是正数
* 则重叠的情况下，即当前可能子数组的左边界小于等于上一个子数组的右边界
  选择较短的一个子数组即可
* 求完所有可能后，挑两个长度最小的即可
*/
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int arr_size=arr.size();
        int sum=0;
        map<int,int> helper;
        int left=0;
        for (int i=0;i<arr_size;++i)
        {
            sum+=arr.at(i);
            if (sum>target)
            {
                while (left<=i && sum>target)
                {
                    sum-=arr.at(left);
                    ++left;
                }
            }
            else if (sum<target)
            {
                continue;
            }
            //sum==target
            if (sum==target)
            {
                int cur=i-left+1;
                if (helper.empty())
                {
                    helper[i]=cur;
                    continue;
                }
                auto p=helper.end();
                --p;
                if ((p->first)>=left)
                {
                    if (cur<(p->second))
                    {
                        helper.erase(p);
                        helper[i]=cur;
                    }
                }
                else
                    helper[i]=cur;
            }
        }
        if (helper.size()<2)
            return -1;
        priority_queue<int,vector<int>,less<int>> ans;
        for (auto &i:helper)
        {
            ans.push(i.second);
            if (ans.size()>2)
                ans.pop();
        }
        int result=ans.top();
        ans.pop();
        return result+ans.top();
    }
};
