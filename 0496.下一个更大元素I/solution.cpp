class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int nums2_size=nums2.size();
        for (int i:nums1)
        {
            int j=0;
            for (;j<nums2_size;++j)
                if (nums2.at(j)==i)
                    break;
            bool judge_find=false;
            for (;j<nums2_size;++j)
                if (nums2.at(j)>i)
                {
                    ans.push_back(nums2.at(j));
                    judge_find=true;
                    break;
                }
            if (!judge_find)
                ans.push_back(-1);
        }
        return ans;
    }
};
