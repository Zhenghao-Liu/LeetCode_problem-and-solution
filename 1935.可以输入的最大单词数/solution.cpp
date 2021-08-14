class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> cnt(26);
        for (char i:brokenLetters) {
            cnt.at(i-'a')=1;
        }
        vector<int> cur(26);
        int sz=text.size();
        int ans=0;
        for (int i=0;i<=sz;i++) {
            if (i==sz || text.at(i)==' ') {
                bool can=true;
                for (int j=0;j<26;j++) {
                    if (cur.at(j)==1 && cnt.at(j)==1) {
                        can=false;
                        break;
                    }
                }
                if (can) {
                    ans++;
                }
                fill(cur.begin(),cur.end(),0);
                continue;
            }
            cur.at(text.at(i)-'a')=1;
        }
        return ans;
    }
};