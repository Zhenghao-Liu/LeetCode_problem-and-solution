class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> mask;
        for (char &i:s)
            ++mask[i];
        unordered_map<char,bool> answer_mask;
        for (auto &i:mask)
            answer_mask.insert({i.first,false});
        stack<char> helper_stack;
        for (char &i:s)
        {
            --mask.at(i);
            if (answer_mask.at(i))
                continue;
            while (!helper_stack.empty() && i<helper_stack.top() && mask.at(helper_stack.top())>0)
            {
                answer_mask.at(helper_stack.top())=false;
                helper_stack.pop();
            }
            helper_stack.push(i);
            answer_mask.at(i)=true;
        }
        string answer="";
        while(!helper_stack.empty())
        {
            answer+=helper_stack.top();
            helper_stack.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};
