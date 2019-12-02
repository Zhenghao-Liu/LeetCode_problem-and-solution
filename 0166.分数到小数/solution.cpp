//如果出现重复的余数则代表有循环小数
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        //分母为0则除法无意义
        if (denominator==0)
            return "";
        //分子为0则直接输出"0"
        if (numerator==0)
            return "0";
        string answer;
        //区分正负号
        if ((numerator>0) ^ (denominator>0))
            answer.append("-");
        //为了防止abs(INT_MIN)结果还是INT_MIN的情况
        //注意abs是根据里面类型来，所以(long long)(abs(INT_MIN))结果还是INT_MIN
        long long numerator_m=numerator,denominator_m=denominator;
        numerator_m=abs(numerator_m);
        denominator_m=abs(denominator_m);
        //整数的部分
        answer.append(to_string(numerator_m/denominator_m));
        numerator_m=numerator_m%denominator_m;
        //没有小数的话
        if (numerator_m==0)
            return answer;
        answer.append(".");
        //记录余数出现的位置，为了后面加"()"
        unordered_map<int,int> position;
        int index=answer.size();
        //余数为0，或者找到了重复余数时停止除法
        while (numerator_m!=0 && position.find(numerator_m)==position.end())
        {
            position.insert({numerator_m,index});
            ++index;
            numerator_m=numerator_m*10;
            answer.append(to_string(numerator_m/denominator_m));
            numerator_m=numerator_m%denominator_m;
        }
        if (position.find(numerator_m)!=position.end())
        {
            answer.insert(position.at(numerator_m),"(");
            answer.append(")");
        }
        return answer;
    }
};
