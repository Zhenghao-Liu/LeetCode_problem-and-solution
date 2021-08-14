class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int cur=0;
        int ans=0;
        for (int i:rungs) {
            ans+=(i-1-cur)/dist;
            cur=i;
        }
        return ans;
    }
};