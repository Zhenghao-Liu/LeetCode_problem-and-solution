class Solution {
public:
    vector<int> minOperations(string b) {
        int sz=b.size();
        int l=0,r=0;
        int lc=0,rc=0;
        for (int i=1;i<sz;i++) {
            if (b.at(i)=='1') {
                r+=i;
                rc++;
            }
        }
        vector<int> ans(sz);
        ans.at(0)=r;
        for (int i=1;i<sz;i++) {
            if (b.at(i-1)=='1') {
                lc++;
            }
            if (b.at(i)=='1') {
                rc--;
                r--;
            }
            l+=lc;
            r-=rc;
            ans.at(i)=l+r;
        }
        return ans;
    }
};
