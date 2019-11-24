class Solution {
public:
    string reverseWords(string s) {
        stack<string> s_stack;
        int not_blank_i=0,s_size=s.size();
        if (s_size==0)
            return "";
        for (;not_blank_i<s_size;++not_blank_i)
            if (s.at(not_blank_i)!=' ')
                break;
        string temporary="";
        for (int i=not_blank_i;i<s_size;++i)
            if (s.at(i)==' ')
            {
                while (i<s_size && s.at(i)==' ')
                    ++i;
                --i;
                s_stack.push(temporary);
                temporary="";
            }
            else
                temporary=temporary+s.at(i);
        if (s.at(s_size-1)!=' ')
            s_stack.push(temporary);
        string answer="";
        while (!s_stack.empty())
        {
            answer=answer+s_stack.top()+' ';
            s_stack.pop();
        }
        answer.erase(answer.end()-1);
        return answer;
    }
};
