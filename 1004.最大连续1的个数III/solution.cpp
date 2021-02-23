class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int sz=A.size();
        int ans=0;
        int cnt=0;
        int l=0,r=0;
        for (l=0;l<sz;l++) {
            while (r<sz && cnt+(A.at(r)^1)<=K) {
                cnt+= A.at(r)==0 ? 1 : 0;
                r++;
            }
            ans=max(ans,r-l);
            cnt-= A.at(l)==0 ? 1 : 0;
        }
        return ans;
    }
};
