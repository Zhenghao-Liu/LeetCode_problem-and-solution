class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int l=0,r=nums.size()-1;
        while (l<r)
        {
            int ll=nums.at(l);
            int rr=nums.at(r);
            if (ll+rr==k)
            {
                ++ans;
                ++l;
                --r;
            }
            else if (ll+rr>k)
                --r;
            else
                ++l;
        }
        return ans;
    }
};
