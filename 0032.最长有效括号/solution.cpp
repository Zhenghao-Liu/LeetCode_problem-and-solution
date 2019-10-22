class Solution {
public:
    int longestValidParentheses(string s) {
        int s_size=s.size();
        stack<int> position;
        position.push(-1);
        int answer=0;
        for (int i=0;i<s_size;++i)
            if (s.at(i)=='(')
                position.push(i);
            else
            {
                position.pop();
                if (position.empty())
                    position.push(i);
                else
                    answer=max(answer,i-position.top());
            }
        return answer;
    }
};
