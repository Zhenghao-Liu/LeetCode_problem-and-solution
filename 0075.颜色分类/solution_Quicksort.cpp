class Solution {
public:
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
};
