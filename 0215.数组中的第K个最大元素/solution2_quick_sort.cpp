/*
* 快排思想，但是找povitkey随机查找这样效率更高
* 随机找povitkey后与nums[left]交换位置就等同于之前的找第一个值为povitkey的步骤了
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return qucik_sort(nums,0,nums.size()-1,nums.size()-k);
    }
    int qucik_sort(vector<int> &nums,int start,int end,int target)
    {
        int povitkey=rand()%(end-start+1)+start;
        int povitkey_value=nums.at(povitkey);
        swap(nums.at(start),nums.at(povitkey));
        int left=start,right=end;
        while (left<right)
        {
            while (left<right)
            {
                if (nums.at(right)<povitkey_value)
                {
                    nums.at(left)=nums.at(right);
                    ++left;
                    break;
                }
                else
                    --right;
            }
            while (left<right)
            {
                if (nums.at(left)>povitkey_value)
                {
                    nums.at(right)=nums.at(left);
                    --right;
                    break;
                }
                else
                    ++left;
            }
        }
        nums.at(left)=povitkey_value;
        if (left==target)
            return povitkey_value;
        else if (left<target)
            return qucik_sort(nums,left+1,end,target);
        else
            return qucik_sort(nums,start,left-1,target); 
    }
};
