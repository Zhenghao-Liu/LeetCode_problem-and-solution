class Solution {
public:
    int search(vector<int>& nums, int target) {
        int nums_size=nums.size();
        int left=0,right=nums_size-1;
        while (left<=right)
        {
            int mid=left+((right-left)>>1);
            if (nums.at(mid)==target)
                return mid;
            if (nums.at(left)==target)
                return left;
            if (nums.at(right)==target)
                return right;
            //左边有序
            if (nums.at(mid)>nums.at(left))
            {
                if (target>=nums.at(left) && target<=nums.at(mid))
                    right=mid-1;
                else
                    left=mid+1;
            }
            //右边有序
            else
            {
                if (target>=nums.at(mid) && target<=nums.at(right))
                    left=mid+1;
                else
                    right=mid-1;
            }
        }
        return -1;
    }
};
