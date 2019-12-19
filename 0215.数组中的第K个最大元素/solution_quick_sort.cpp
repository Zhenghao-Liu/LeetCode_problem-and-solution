class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index=nums.size()-k;
        return quick_sort(nums,0,nums.size()-1,index);
    }
    int quick_sort(vector<int>& nums,int low,int high,int& index)
    {
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
        if (left==index)
            return povitkey;
        else if (left>index)
            return quick_sort(nums,low,left-1,index);
        else
            return quick_sort(nums,left+1,high,index);
    }
};
