class Solution {
public:
    string largestOddNumber(string num) {
        int ans=-1;
        int sz=num.size();
        for (int i=sz-1;i>=0;i--) {
            int c=num.at(i)-'0';
            if ((c%2)==1) {
                ans=i;
                break;
            }
        }
        return num.substr(0,ans+1);
    }
};