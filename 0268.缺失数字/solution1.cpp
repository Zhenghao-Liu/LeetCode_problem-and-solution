//类似于哈希表法，但是没有用到常数存储空间
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int nums_size=nums.size();
        vector<bool> v(nums_size+1,false);
        for (int &i:nums)
            v.at(i)=true;
        for (int i=0;i<nums_size+1;++i)
            if (!v.at(i))
                return i;
        return 0;
    }
};
