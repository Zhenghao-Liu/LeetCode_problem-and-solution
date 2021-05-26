class Solution {
public:
    string sortSentence(string s) {
        vector<string> vec(9);
        string cur;
        for (char &i:s) {
            if (i==' ') {
                continue;
            } else if (i>='0' && i<='9'){
                vec.at(i-'1')=cur;
                cur="";
            } else {
                cur+=i;
            }
        }
        string ans;
        for (string &i:vec) {
            if (i=="") {
                break;
            }
            ans+=i+" ";
        }
        ans.pop_back();
        return ans;
    }
};