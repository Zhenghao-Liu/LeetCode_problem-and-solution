/*
* 先快排再二分
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size()==0)
            return false;
        sortColors(nums);
        return searchRange(nums,target);
    }
    void sortColors(vector<int>& nums)
	{
        int nums_size=nums.size();
        if (nums_size<2)
            return;
        quick_sort(nums,0,nums_size-1);
    }
    void quick_sort(vector<int>& nums,int low,int high)
    {
        if (low>=high)
            return;
        int povitkey=nums.at(low),left=low,right=high;
        while (left<right)
        {
            while (left<right)
                if (nums.at(right)<povitkey)
                {
                    nums.at(left)=nums.at(right);
                    ++left;
                    break;
                }
                else
                    --right;
            while (left<right)
                if (nums.at(left)>povitkey)
                {
                    nums.at(right)=nums.at(left);
                    --right;
                    break;
                }
                else
                    ++left;
        }
        nums.at(left)=povitkey;
        quick_sort(nums,low,left-1);
        quick_sort(nums,left+1,high);
    }
    bool searchRange(vector<int>& nums, int target) {
        int nums_size=nums.size();
        int left=0,right=nums_size-1,position=-1,middle,middle_value;
        while (left<=right)
        {
            middle=(left+right)/2;
            middle_value=nums.at(middle);
            if (middle_value==target)
            {
                return true;
            }
            else if (middle_value<target)
                left=middle+1;
            else
                right=middle-1;
        }
        return false;;
    }
};
