//[set_intersection](https://blog.csdn.net/u014023993/article/details/47614381)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        nums1.erase(set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),nums1.begin()),nums1.end());
        return nums1;
    }
};
