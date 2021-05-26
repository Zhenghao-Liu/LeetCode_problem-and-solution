class Solution {
public:
    int minSwaps(string s) {
        int o=0,z=0;
        for (char i:s) {
            if (i=='0') {
                z++;
            } else {
                o++;
            }
        }
        if (!(z==o || z==o+1 || o==z+1)) {
            return -1;
        }
        int sz=s.size();
        if (z==o) {
            int r1=0,r2=0;
            int idx=0;
            for (int i=0;i<sz;i++) {
                int cur=s.at(i)-'0';
                if (cur==idx) {
                    r2++;
                } else {
                    r1++;
                }
                idx^=1;
            }
            return min(r1,r2)/2;
        } else if (z==o+1) {
            int idx=0;
            int ans=0;
            for (int i=0;i<sz;i++) {
                int cur=s.at(i)-'0';
                if (cur!=idx) {
                    ans++;
                }
                idx^=1;
            }
            return ans/2;
        } else {
            int idx=1;
            int ans=0;
            for (int i=0;i<sz;i++) {
                int cur=s.at(i)-'0';
                if (cur!=idx) {
                    ans++;
                }
                idx^=1;
            }
            return ans/2;
        }
        return -1;
    }
};