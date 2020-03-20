class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss=1;
        int nums_size=nums.size();
        int ans=0,index=0;
        while (miss<=n)
            if (index<nums_size && nums.at(index)<=miss)
            {
                miss+=nums.at(index);
                ++index;
            }
            else
            {
                miss+=miss;
                ++ans;
            }
        return ans;
    }
};
