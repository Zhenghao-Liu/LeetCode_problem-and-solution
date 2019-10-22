static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if (0==m)
            return (nums2.at(n/2)+nums2.at((n/2)-(n-1)%2))/2.0;
        else if (0==n)
            return (nums1.at(m/2)+nums1.at((m/2)-(m-1)%2))/2.0;
        vector<int> ans=nums1;
        ans.insert(ans.end(),nums2.begin(),nums2.end());
        sort(ans.begin(),ans.end());
        int l=n+m;
        return (ans.at(l/2)+ans.at((l/2)-(l-1)%2))/2.0;
    }
};
