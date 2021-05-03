class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;
        int cnt=0;
        int sz=s.size();
        for (char i:s) {
            if (i==' ') {
                cnt++;
            }
            if (cnt==k) {
                break;
            }
            ans+=i;
        }
        return ans;
    }
};