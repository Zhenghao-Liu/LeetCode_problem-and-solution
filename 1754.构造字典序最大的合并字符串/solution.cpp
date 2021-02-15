class Solution {
public:
    string largestMerge(string word1, string word2) {
        int sz1=word1.size();
        int sz2=word2.size();
        int i=0,j=0;
        string ans;
        while (i<sz1 && j<sz2) {
            if (word1.substr(i)>word2.substr(j)) {
                ans+=word1.at(i);
                i++;
            } else {
                ans+=word2.at(j);
                j++;
            }
        }
        if (i<sz1) {
            ans+=word1.substr(i);
        }
        if (j<sz2) {
            ans+=word2.substr(j);
        }
        return ans;
    }
};
