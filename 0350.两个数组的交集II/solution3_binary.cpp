class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums2.begin(),nums2.end());
        vector<int> ans;
        for (int &i:nums1)
            if (binary_search(nums2,i))
                ans.push_back(i);
        return ans;
    }
    bool binary_search(vector<int> & nums,int target)
    {
        int left=0,right=nums.size()-1;
        while (left<=right)
        {
            int mid=left+((right-left)>>1);
            if (nums.at(mid)==target)
            {
                nums.erase(nums.begin()+mid);
                return true;
            }
                
            else if (nums.at(mid)<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return false;
    }
};
