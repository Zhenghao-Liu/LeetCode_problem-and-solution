class Solution {
public:
    void sortColors(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size<2)
            return;
        int left=0;
        for (int i=0;i<nums_size;++i)
            if (nums.at(i)==0)
                swap(nums.at(i),nums.at(left++));
        int right=nums_size-1;
        for (int i=nums_size-1;i>=left;--i)
            if (nums.at(i)==2)
                swap(nums.at(i),nums.at(right--));  
    }
};
