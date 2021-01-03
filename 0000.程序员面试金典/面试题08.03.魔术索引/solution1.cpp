class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int nums_size=nums.size();
        for (int i=0;i<nums_size;++i)
            if (nums.at(i)==i)
                return i;
        return -1;
    }
};
