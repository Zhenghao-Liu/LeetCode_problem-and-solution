class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> ust;
        int sz=word.size();
        for (int i=0;i<sz;i++) {
            if (!(word.at(i)>='0' && word.at(i)<='9')) {
                continue;
            }
            string s;
            int j;
            for (j=i;j<sz;j++) {
                if (!(word.at(j)>='0' && word.at(j)<='9')) {
                    break;
                }
                s+=word.at(j);
            }
            i=j;
            int k=0;
            for (k=0;k<s.size();k++) {
                if (s.at(k)!='0') {
                    break;
                }
            }
            if (k==s.size()) {
                ust.insert("0");
            } else {
                ust.insert(s.substr(k));
            }
        }
        return ust.size();
    }
};