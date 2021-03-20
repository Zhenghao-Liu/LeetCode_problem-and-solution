class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int sz=nums.size();
        int l=k,r=k;
        int mi=nums.at(k);
        int ans=nums.at(k);
        while (l!=0 || r!=sz-1) {
            if (l==0) {
                r++;
                mi=min(mi,nums.at(r));
            } else if (r==sz-1) {
                l--;
                mi=min(mi,nums.at(l));
            } else if (nums.at(l-1)>nums.at(r+1)){
                l--;
                mi=min(mi,nums.at(l));
            } else {
                r++;
                mi=min(mi,nums.at(r));
            }
            ans=max(ans,mi*(r-l+1));
        }
        return ans;
    }
};
