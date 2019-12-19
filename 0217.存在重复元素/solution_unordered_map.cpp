class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> nums_map;
        for (int &i:nums)
        {
            ++nums_map[i];
            if (nums_map.at(i)>=2)
                return true;
        }
        return false;
    }
};
