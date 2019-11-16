class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int nums_size=nums.size();
        unordered_map<int,int> nums_map;
        for (int i:nums)
            if (nums_map.find(i)==nums_map.end())
                nums_map.insert({i,1});
            else
                nums_map.erase(i);
        return nums_map.begin()->first;
    }
};
