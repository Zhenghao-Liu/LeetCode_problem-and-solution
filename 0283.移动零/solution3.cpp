class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nums_size=nums.size();
        for (int i=0,left=0;i<nums_size;++i)
            if (nums.at(i)!=0)
                swap(nums.at(left++),nums.at(i));
    }
};
