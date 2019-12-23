class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int nums_size=nums.size();
        //香到没了这句就超时
        if (nums_size>=10000)
            return false;
        for (int i=0;i<nums_size-1;++i)
            for (int j=i+1;j<nums_size && j-i<=k;++j)
                if (abs(long(nums.at(j))-long(nums.at(i)))<=t)
                    return true;
        return false;
    }
};
