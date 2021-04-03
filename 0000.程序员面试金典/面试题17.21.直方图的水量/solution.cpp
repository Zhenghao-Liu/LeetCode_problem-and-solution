class Solution {
public:
    int trap(vector<int>& height) {
        int sz=height.size();
        vector<int> l2r(sz),r2l(sz);
        for (int i=1;i<sz;i++) {
            l2r.at(i)=max(l2r.at(i-1),height.at(i-1));
        }
        for (int i=sz-2;i>=0;i--) {
            r2l.at(i)=max(r2l.at(i+1),height.at(i+1));
        }
        int ans=0;
        for (int i=1;i<sz-1;i++) {
            int diff=min(l2r.at(i),r2l.at(i))-height.at(i);
            ans+=diff>0 ? diff : 0;
        }
        return ans;
    }
};