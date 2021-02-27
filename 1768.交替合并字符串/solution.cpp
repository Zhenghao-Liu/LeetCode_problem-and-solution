class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int szA=word1.size();
        int szB=word2.size();
        string ans;
        int p1=0,p2=0;
        while (p1<szA && p2<szB) {
            ans+=word1.at(p1++);
            ans+=word2.at(p2++);
        }
        if (p1<szA) {
            ans+=word1.substr(p1);
        }
        if (p2<szB) {
            ans+=word2.substr(p2);
        } 
        return ans;
    }
};
