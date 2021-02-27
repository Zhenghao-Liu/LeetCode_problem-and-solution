class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sz=customers.size();
        int all=0;
        for (int i=0;i<sz;i++) {
            if (grumpy.at(i)==0) {
                all+=customers.at(i);
            }
        }
        int ans=all;
        int win=0;
        for (int i=0;i<X-1;i++) {
            if (grumpy.at(i)==1) {
                win+=customers.at(i);
            }
        }
        for (int i=X-1;i<sz;i++) {
            if (grumpy.at(i)==1) {
                win+=customers.at(i);
            }
            if (i-X>=0 && grumpy.at(i-X)==1) {
                win-=customers.at(i-X);
            }
            ans=max(ans,win+all);
        }
        return ans;
    }
};
