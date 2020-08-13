class Ma
{
public:
    //Ax+B
    int A;
    int B;
    Ma():A(0),B(0){}
};
class Solution {
public:
    string solveEquation(string equation) {
        Ma left;
        int equal_index=helper(equation,0,left);
        Ma right;
        helper(equation,equal_index+1,right);
        //cx=d
        int c=left.A-right.A;
        int d=right.B-left.B;
        if (c==0 && d!=0)
            return "No solution";
        else if (c==0 && d==0)
            return "Infinite solutions";
        return "x="+to_string(d/c);
    }
    int helper(string & s,int start,Ma &ma)
    {
        int s_size=s.size();
        int num=0;
        int sign=1;
        bool judge_x=false;
        bool judge_num=false;
        for (int i=start;i<=s_size;++i)
        {
            if (i==s_size || s.at(i)=='=' || s.at(i)=='+' || s.at(i)=='-')
            {
                if (judge_x)
                {
                    if (!judge_num)
                        num=1;
                    ma.A+=sign*num;
                }
                else
                {
                    ma.B+=sign*num;
                }
                if (i==s_size || s.at(i)=='=')
                    return i;
                num=0;
                sign=s.at(i)=='-' ? -1 : 1;
                judge_x=false;
                judge_num=false;
                continue;
            }
            if (s.at(i)=='x')
            {
                judge_x=true;
                continue;
            }
            judge_num=true;
            num=num*10+(s.at(i)-'0');
        }
        return -1;
    }
};
