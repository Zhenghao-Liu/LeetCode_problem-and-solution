class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<int> ust;
        int sz=s.size();
        vector<int> ltr(sz);
        vector<int> rtl(sz);
        ltr.at(0)=1<<(s.at(0)-'a');
        for (int i=1;i<sz;i++) {
            char c=s.at(i);
            ltr.at(i)=ltr.at(i-1)|(1<<(c-'a'));
        }
        rtl.at(sz-1)=1<<(s.at(sz-1)-'a');
        for (int i=sz-2;i>=0;i--) {
            char c=s.at(i);
            rtl.at(i)=rtl.at(i+1)|(1<<(c-'a'));
        }
        for (int i=1;i<sz-1;i++) {
            char c=s.at(i);
            int l=ltr.at(i-1),r=rtl.at(i+1);
            for (int j=0;j<26;j++) {
                if (((1<<j)&l)!=0 && ((1<<j)&r)!=0) {
                    ust.insert(j*26+(c-'a'));
                }
            }
        }
        return ust.size();
    }
};