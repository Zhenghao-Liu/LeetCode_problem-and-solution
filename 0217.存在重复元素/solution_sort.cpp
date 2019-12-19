class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int nums_size=nums.size();
        for (int i=1;i<nums_size;++i)
            if (nums.at(i)==nums.at(i-1))
                return true;
        return false;
    }
};
