class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int sz1=nums1.size(),sz2=nums2.size();
        int j=0;
        int ans=0;
        for (int i=0;i<sz1;i++) {
            while (j<sz2 && i>j) {
                j++;
            }
            while (j<sz2 && nums1.at(i)<=nums2.at(j)) {
                ans=max(j-i,ans);
                j++;
            }
        }
        return ans;
    }
};