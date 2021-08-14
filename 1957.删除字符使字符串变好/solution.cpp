class Solution {
public:
    string makeFancyString(string s) {
        char lst='!';
        string ans;
        int cnt=1;
        for (char i:s) {
            if (i!=lst) {
                lst=i;
                cnt=1;
                ans+=i;
            } else {
                cnt++;
                if (cnt>2) {
                    continue;
                }
                ans+=i;
            }
        }
        return ans;
    }
};