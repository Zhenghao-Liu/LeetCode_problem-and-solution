class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans=0;
        int sz=s.size();
        for (int i=2;i<sz;i++) {
            char a=s.at(i),b=s.at(i-1),c=s.at(i-2);
            if (a!=b && b!=c && a!=c) {
                ans++;
            }
        }
        return ans;
    }
};