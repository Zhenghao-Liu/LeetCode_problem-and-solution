class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur=0;
        int ans=0;
        for (int i:gain) {
            cur+=i;
            ans=max(ans,cur);
        }
        return ans;
    }
};
