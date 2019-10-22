/*
*先二分查找，再while两边拓展
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int nums_size=nums.size();
        if (nums_size==0)
            return {-1,-1};
        int left=0,right=nums_size-1,position=-1,middle,middle_value;
        while (left<=right && left>=0 && right<=nums_size-1)
        {
            middle=(left+right)/2;
            middle_value=nums.at(middle);
            if (middle_value==target)
            {
                position=middle;
                break;
            }
            else if (middle_value<target)
                left=middle+1;
            else
                right=middle-1;
        }
        if (position==-1)
            return {-1,-1};
        else
        {
            left=right=position;
            while (left>0 && nums.at(left-1)==nums.at(left))
                --left;
            while (right<nums_size-1 && nums.at(right+1)==nums.at(right))
                ++right;
            return {left,right};
        }   
    }
};
