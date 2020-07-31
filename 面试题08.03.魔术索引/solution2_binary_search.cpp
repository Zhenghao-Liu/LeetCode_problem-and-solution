class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        return binary_search(nums,0,nums.size()-1);
    }
    int binary_search(vector<int> &nums,int start,int end)
    {
        if (start>end)
            return -1;
        int mid=start+(end-start)/2;
        int left=binary_search(nums,start,mid-1);
        if (left!=-1)
            return left;
        else if (nums.at(mid)==mid)
            return mid;
        return binary_search(nums,mid+1,end);
    }
};
