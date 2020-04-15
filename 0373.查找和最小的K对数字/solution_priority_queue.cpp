/*
* 对于所有的排列无非就只有nums1_size*nums2_size种
* 可以把他们分为nums1[0]配上所有nums2[0~size-1]
               nums[1]配上所有nums2[0~size-1]
               ···即所有nums[i]
* 将nums1元素设为A,将nums2元素设为B，即所有组合都可以用[A,B]表示
* 我们可以列举出所有的A，然后初始化B为nums2[0]，因为这样一定求和是B中最小的
* 通过比较所有可能[A,nums[0]]来找出最小，倘若第x个A和nums[0]最小，则将B的指针向右移更新为nums[1]，以此类推一直比较
* 为了排序可以采用priority_queue，但是有一个问题，难道指针移动要一个一个遍历会nums2嘛？万一有重复的呢
* 所以采用特别的存储结构pair<int,pair<int,int>>，<A<B,C>>,A是u,B是v在nums2的索引,C是v
*/
struct cmp
{
    bool operator()(const pair<int,pair<int,int>> &_1,const pair<int,pair<int,int>> &_2) const
    {
        //注意堆的重载方式和普通sort的重载不同，现在是和最小的放前面top
        return _1.first+_1.second.second>_2.first+_2.second.second;
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int nums1_size=nums1.size();
        int nums2_size=nums2.size();
        if (nums1_size==0 || nums2_size==0)
            return {};
        //<A,<B,C>>,A是u,B是v在nums2的索引,C是v
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>> ,cmp> helper;
        for (int &i:nums1)
            helper.push(make_pair(i,make_pair(0,nums2.at(0))));
        vector<vector<int>> ans;
        while (!helper.empty())
        {
            auto top=helper.top();
            helper.pop();
            ans.push_back({top.first,top.second.second});
            if (ans.size()==k)
                break;
            if (top.second.first+1<nums2_size)
            {
                ++top.second.first;
                top.second.second=nums2.at(top.second.first);
                helper.push(top);
            }
        }
        return ans;
    }
};
