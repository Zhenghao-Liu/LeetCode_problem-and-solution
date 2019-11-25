//若写成nums.at(mid)>nums.at(left),应在left+1=right时退出，判断两个的最小值
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1,mid;
        while (left<right)
        {
            mid=(left+right)/2;
            if (nums.at(mid)>nums.at(right))
                left=mid+1;
            else
                right=mid;
        }
        return nums.at(left);
    }
};
