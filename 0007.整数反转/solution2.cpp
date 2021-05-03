/*
 * ans*10+cur<=INT_MAX
 * ans*10<=INT_MAX-cur
 * ans<=(INT_MAX-cur)/10
 */
class Solution {
public:
    int reverse(int x) {
        int sign=x>=0 ? 1 : -1;
        string s=to_string(x);
        if (sign==-1) {
            s=s.substr(1);
        }
        int ans=0;
        int upper=(INT_MAX)/10;
        while (!s.empty()) {
            int cur=s.back()-'0';
            s.pop_back();
            if (ans>upper) {
                return 0;
            }
            ans=ans*10+cur;
        }
        if (sign==-1) {
            return ans==INT_MAX ? 0 : -ans;
        }
        return ans;
    }
};