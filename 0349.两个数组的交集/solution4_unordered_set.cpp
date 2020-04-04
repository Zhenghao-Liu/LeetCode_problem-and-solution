class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set_nums1(nums1.begin(),nums1.end());
        unordered_set<int> ans;
        for (int &i:nums2)
            if (set_nums1.count(i))
                ans.insert(i);
        return vector<int>(ans.begin(),ans.end());
    }
};
