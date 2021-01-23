class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& r) {
        int mx=INT_MIN;
        for (vector<int> &i:r) {
            mx=max(mx,min(i.at(0),i.at(1)));
        }
        int ans=0;
        for (vector<int> &i:r) {
            int ii=min(i.at(0),i.at(1));
            if (ii==mx) {
                ans++;
            }
        }
        return ans;
    }
};
