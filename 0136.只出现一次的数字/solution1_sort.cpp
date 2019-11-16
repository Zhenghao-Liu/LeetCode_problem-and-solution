class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int nums_size=nums.size();
        for (int i=0;i<nums_size-1;i=i+2)
            if (nums.at(i)!=nums.at(i+1))
                return nums.at(i);
        return nums.at(nums_size-1);
    }
};
