// 滑动窗口
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int sz=s.size();
        vector<int> cst(sz);
        for (int i=0;i<sz;i++) {
            cst.at(i)=abs((int)s.at(i)-(int)t.at(i));
        }
        int ans=0;
        int r=0,l=0;
        int sum=0;
        for (l=0;l<sz;l++) {
            while (r<sz && sum+cst.at(r)<=maxCost) {
                sum+=cst.at(r);
                r++;
            }
            ans=max(r-l,ans);
            sum-=cst.at(l);
        }
        return ans;
    }
};
