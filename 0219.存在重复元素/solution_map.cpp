class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int nums_size=nums.size();
        unordered_map<int,int> all_p;
        for (int i=0;i<nums_size;++i)
            if (all_p.count(nums.at(i))==0)
                all_p.insert({nums.at(i),i});
            else
            {
                if (i-all_p.at(nums.at(i))<=k)
                    return true;
                all_p.at(nums.at(i))=i;
            }
        return false;
    }
};
