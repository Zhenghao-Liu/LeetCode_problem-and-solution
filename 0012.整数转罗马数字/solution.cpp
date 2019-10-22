static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    string intToRoman(int num) {
        int math_number[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string roman_number[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int res=num;
        string ans="";
        for (int i=0;i<13;++i)
            while (res>=math_number[i])
            {
                ans=ans+roman_number[i];
                res=res-math_number[i];
            }
        return ans;
    }
};
