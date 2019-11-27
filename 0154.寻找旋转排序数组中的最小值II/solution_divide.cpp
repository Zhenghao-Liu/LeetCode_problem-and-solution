class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1,mid;
        while (left<right)
        {
            mid=(left+right)/2;
            //相比于上一题就多了这一句
            while (mid+1 < right && nums.at(mid) == nums.at(right))
                ++mid;
            if (nums.at(mid)>nums.at(right))
                left=mid+1;
            else
                right=mid;
        }
        return nums.at(left);
    }
};
