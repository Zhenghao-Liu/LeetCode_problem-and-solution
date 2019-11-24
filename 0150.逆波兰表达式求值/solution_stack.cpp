class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tokens_stack;
        int temp_a,temp_b;
        for (string &i:tokens)
            if (i=="+" || i=="-" || i=="*" || i=="/")
            {
                temp_a=tokens_stack.top();
                tokens_stack.pop();
                temp_b=tokens_stack.top();
                tokens_stack.pop();
                if (i=="+")
                    tokens_stack.push(temp_b+temp_a);
                else if (i=="-")
                    tokens_stack.push(temp_b-temp_a);
                else if (i=="*")
                    tokens_stack.push(temp_b*temp_a);
                else if (i=="/")
                    tokens_stack.push(temp_b/temp_a);
            }
            else
                tokens_stack.push(stoi(i));
        return tokens_stack.top();
    }
};
