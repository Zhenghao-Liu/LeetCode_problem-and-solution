//最大公因数
int get_gcd(int a,int b)
{
    if (a<b)
        swap(a,b);
    int temporary;
    while (b!=0)
    {
        temporary=a%b;
        a=b;
        b=temporary;
    }
    return a;
}
//最小公倍数
int get_lcm(int a,int b)
{
    return a*b/get_gcd(a,b);
}
class fraction
{
public:
    int above=0;//分子
    int below=1;//分母
    fraction(){
        above=0;
        below=1;
    }
    void reduction()
    {
        //约分
        int gcd(get_gcd(above,below));
        above=above/gcd;
        below=below/gcd;
        if (above>0 && below<0)
        {
            above=-above;
            below=-below;
        }
    }
    void makeCommond(fraction& another_fraction)
    {
        //通分
        int temporary(below);
        below=get_lcm(below,another_fraction.below);
        above=above*(below/temporary);
    }
    fraction add(fraction another_fraction)
    {
        fraction temporary(*this);
        temporary.makeCommond(another_fraction);
        another_fraction.makeCommond(temporary);
        temporary.above=temporary.above+another_fraction.above;
        temporary.reduction();
        return temporary;
    }
};
class Solution {
public:
    string fractionAddition(string expression) {
        int size=expression.size();
        fraction ans;
        fraction another_fraction;
        int sign=1;
        int num=0;
        int _above=0,_below=1;
        for (int i=0;i<=size;++i)
        {
            if (i==size || expression.at(i)=='-' || expression.at(i)=='+')
            {
                if (i!=0)
                    _below=num;
                another_fraction.above=_above*sign;
                another_fraction.below=_below;
                if (i<size)
                    sign= expression.at(i)=='-' ? -1 : 1;
                ans=ans.add(another_fraction);
                num=0;
                continue;
            }
            if (expression.at(i)=='/')
            {
                _above=num;
                num=0;
                continue;
            }
            if (expression.at(i)>='0' && expression.at(i)<='9')
            {
                num=num*10+(expression.at(i)-'0');
                continue;
            }
        }
        return to_string(ans.above)+"/"+to_string(ans.below);
    }
};
