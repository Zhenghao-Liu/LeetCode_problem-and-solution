class Solution {
public:
    int calculate(string s) {
        stack<int> helper_stack;
        int sign=1,answer=0,s_size=s.size();
        for (int i=0;i<s_size;++i)
        {
            if (s.at(i)==' ')
                continue;
            if (s.at(i)>='0')
            {
                int num=0;
                while (i<s_size && s.at(i)>='0')
                {
                    num=num*10-'0'+s.at(i);
                    ++i;
                }
                answer=answer+sign*num;
                --i;
            }
            else if (s.at(i)=='+')
                sign=1;
            else if (s.at(i)=='-')
                sign=-1;
            else if (s.at(i)=='(')
            {
                helper_stack.push(answer);
                helper_stack.push(sign);
                sign=1;
                answer=0;
            }
            else if (s.at(i)==')')
            {
                answer=answer*helper_stack.top();
                helper_stack.pop();
                answer=answer+helper_stack.top();
                helper_stack.pop();
            }
        }
        return answer;
    }
};
