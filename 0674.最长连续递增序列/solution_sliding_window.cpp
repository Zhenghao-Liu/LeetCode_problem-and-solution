class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans=0;
        int nums_size=nums.size();
        for (int i=0;i<nums_size;)
        {
            int j;
            for (j=i+1;j<nums_size;++j)
                if (nums.at(j)<=nums.at(j-1))
                    break;
            ans=max(ans,j-i);
            i=j;
        }
        return ans;
    }
};
