class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& rem) {
        int ssz=s.size(),psz=p.size(),rsz=rem.size();
        int l=0,r=rsz;
        while (l<r) {
            int mid=l+(r-l+1)/2;
            string d=s;
            for (int i=0;i<mid;i++) {
                d.at(rem.at(i))='-';
            }
            int a=0,b=0;
            while (a<ssz && b<psz) {
                if (d.at(a)!=p.at(b)) {
                    a++;
                } else {
                    a++;
                    b++;
                }
            }
            if (b==psz) {
                l=mid;
            } else {
                r=mid-1;
            }
        }
        return l;
    }
};