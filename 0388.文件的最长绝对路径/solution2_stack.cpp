//不用存字符串，直接存长度即可
class Solution {
public:
    int lengthLongestPath(string input) {
        input+='\n';
        int input_size=input.size();
        int ans=0;
        stack<int> helper;
        int count=0;
        bool is_file=false;
        int level=1;
        for (int i=0;i<input_size;++i)
        {
            if (input.at(i)=='\n')
            {
                if (level>helper.size())
                    helper.push(count);
                else
                {
                    int pop_times=helper.size()-level+1;
                    while (pop_times!=0)
                    {
                        helper.pop();
                        --pop_times;
                    }
                    helper.push(count);
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
                count=0;
            }
            if (i>=input_size)
                break;
            ++count;
            if (input.at(i)=='.')
                is_file=true;
        }
        return ans;
    }
};
