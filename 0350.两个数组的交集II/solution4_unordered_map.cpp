//当数组中重复数字过多时用map比set更好
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()<nums2.size())
            return intersect(nums2,nums1);
        unordered_map<int,int> mask_nums1;
        for (int &i:nums1)
            ++mask_nums1[i];
        vector<int> ans;
        for (int &i:nums2)
            if (mask_nums1.find(i)!=mask_nums1.end() && mask_nums1.at(i)>0)
            {
                ans.push_back(i);
                --mask_nums1.at(i);
            }
        return ans;
    }
};
