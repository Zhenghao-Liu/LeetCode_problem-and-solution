//只有0,1,2三种数字，排好0和2,那么1就自动排好了
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        for (int curr=0;curr<=right;)
        {
            if (nums.at(curr)==0)
            {
                swap(nums.at(curr),nums.at(left));
                ++curr;
                ++left;
            }
            else if (nums.at(curr)==2)
            {
                swap(nums.at(curr),nums.at(right));
                --right;
            }
            //else if (nums.at(curr)==1)
            else
                ++curr;
        }
    }
};
