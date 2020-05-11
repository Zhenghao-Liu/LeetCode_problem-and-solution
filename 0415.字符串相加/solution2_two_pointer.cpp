class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1,j=num2.size()-1;
        int sum;
        int num1_i,num2_j;
        int carry=0;
        string ans;
        while (i>=0 || j>=0)
        {
            num1_i= i>=0 ? num1.at(i)-'0' : 0;
            num2_j= j>=0 ? num2.at(j)-'0' : 0;
            sum=carry+num1_i+num2_j;
            ans+=(sum%10+'0');
            carry=sum/10;
            --i;
            --j;
        }
        if (carry==1)
            ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
