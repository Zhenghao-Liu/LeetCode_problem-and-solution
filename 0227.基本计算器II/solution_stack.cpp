class Solution {
public:
    int calculate(string s) {
        int s_size=s.size();
        stack<int> stack_num;
        int num=0;
        char sign='+';
        for (int i=0;i<s_size;++i)
        {
            if (s.at(i)>='0')
                num=num*10-'0'+s.at(i);
            if ((s.at(i)!=' ' && s.at(i)<'0') || i==s_size-1)
            {
                //可以理解为遍历到一个符号时，sign存着上一个符号
                if (sign=='+')
                    stack_num.push(num);
                else if (sign=='-')
                    stack_num.push(-num);
                //'*'或'/'
                else
                {
                    int temp=stack_num.top();
                    stack_num.pop();
                    stack_num.push(sign=='*' ? temp*num : temp/num);
                }
                sign=s.at(i);
                num=0;
            }
        }  
        int answer=0;
        while (!stack_num.empty())
        {
            answer=answer+stack_num.top();
            stack_num.pop();
        }
        return answer;
    }
};
