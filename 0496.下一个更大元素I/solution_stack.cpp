/*
* 因为没有重复，且是找右边第一个比其大的值
* 采用单调递增栈处理nums2，栈顶元素最小，并将结果存入哈希表中即可
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> next_max;
        stack<int> helper;
        int nums2_size=nums2.size();
        for (int i=nums2_size-1;i>=0;--i)
        {
            while (!helper.empty() && helper.top()<=nums2.at(i))
                helper.pop();
            if (!helper.empty())
                next_max[nums2.at(i)]=helper.top();
            helper.push(nums2.at(i));
        }
        vector<int> ans;
        ans.reserve(nums1.size());
        for (int i:nums1)
        {
            auto p=next_max.find(i);
            if (p==next_max.end())
                ans.push_back(-1);
            else
                ans.push_back(p->second);
        }
        return ans;
    }
};
