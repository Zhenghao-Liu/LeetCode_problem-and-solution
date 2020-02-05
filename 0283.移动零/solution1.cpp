class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nums_size=nums.size();
        int left=0,right=0;
        for (int i=0;i<nums_size;++i)
            if (nums.at(i)==0)
                ++right;
            else
            {
                nums.at(left)=nums.at(right);
                ++left;
                ++right;
            }
        for (int i=left;i<nums_size;++i)
            nums.at(i)=0;
    }
};
