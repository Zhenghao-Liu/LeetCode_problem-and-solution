class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size()<num2.size())
            return addStrings(num2,num1);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ans;
        int num1_size=num1.size();
        int num2_size=num2.size();
        int carry=0;
        int sum=0;
        for (int i=0;i<num2_size;++i)
        {
            sum=carry+(num1.at(i)-'0')+(num2.at(i)-'0');
            ans+=(sum%10+'0');
            carry=sum/10;
        }
        for (int i=num2_size;i<num1_size;++i)
        {
            sum=carry+(num1.at(i)-'0');
            ans+=(sum%10+'0');
            carry=sum/10;
        }
        if (carry==1)
            ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
