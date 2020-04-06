class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int nums1_size=nums1.size(),nums2_size=nums2.size();
        int p_1=0,p_2=0;
        vector<int> ans;
        while (p_1<nums1_size && p_2<nums2_size)
            if (nums1.at(p_1)<nums2.at(p_2))
                ++p_1;
            else if (nums1.at(p_1)>nums2.at(p_2))
                ++p_2;
            else
            {
                ans.push_back(nums1.at(p_1));
                ++p_1;
                ++p_2;
            }
        return ans;
    }
};
