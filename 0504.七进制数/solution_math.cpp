class Solution {
public:
    string convertToBase7(int num) {
        if (num==0)
            return "0";
        int sign=num>=0 ? 1 : -1;
        num=abs(num);
        string ans;
        while (num!=0)
        {
            ans+=to_string(num%7);
            num/=7;
        }
        if (sign==-1)
            ans+='-';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
