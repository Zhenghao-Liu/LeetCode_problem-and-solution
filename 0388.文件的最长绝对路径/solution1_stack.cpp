class Solution {
public:
    int lengthLongestPath(string input) {
        input+='\n';
        int input_size=input.size();
        int ans=0;
        stack<int> helper;
        string s;
        bool is_file=false;
        int level=1;
        for (int i=0;i<input_size;++i)
        {
            if (input.at(i)=='\n')
            {
                if (level>helper.size())
                    helper.push(s.size());
                else
                {
                    int pop_times=helper.size()-level+1;
                    while (pop_times!=0)
                    {
                        helper.pop();
                        --pop_times;
                    }
                    helper.push(s.size());
                }
                level=1;
                for (++i;i<input_size && input.at(i)=='\t';++i)
                    ++level;
                if (is_file)
                {
                    stack<int> try_ans_stack=helper;
                    int try_ans=try_ans_stack.size()-1;
                    while (!try_ans_stack.empty())
                    {
                        try_ans+=try_ans_stack.top();
                        try_ans_stack.pop();
                    }
                    if (try_ans>ans)
                        ans=try_ans;
                    is_file=false;
                }
                s.clear();
            }
            if (i>=input_size)
                break;
            s+=input.at(i);
            if (input.at(i)=='.')
                is_file=true;
        }
        return ans;
    }
};
