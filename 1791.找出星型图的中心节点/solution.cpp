class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n;
        for (vector<int> &i:edges) {
            n=max(n,i.at(0));
            n=max(n,i.at(1));
        }
        vector<int> cnt(n+1);
        for (vector<int> &i:edges) {
            cnt.at(i.at(0))++;
            cnt.at(i.at(1))++;
        }
        int ans=-1;
        for (int i=1;i<=n;i++) {
            if (cnt.at(i)==n-1) {
                return i;
            }
        }
        return -1;
    }
};
