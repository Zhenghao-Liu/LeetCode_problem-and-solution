class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nums_size=nums.size();
        int count_zero=0;
        for (int i=0;i<nums_size;++i)
            if (nums.at(i)==0)
                ++count_zero;
            else if (count_zero>0)
            {
                nums.at(i-count_zero)=nums.at(i);
                nums.at(i)=0;
            }
    }
};
