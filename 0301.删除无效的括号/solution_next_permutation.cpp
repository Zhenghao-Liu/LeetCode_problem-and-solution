class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int s_size=s.size();
        //judge_use中1表示保留，0表示删除字符
        vector<int> judge_use(s_size,1);
        int num_of_delete=0;
        unordered_set<string> answer;
        for (int i=0;i<s_size;++i)
        {
            //从删除0个字符开始
            for (int j=0;j<num_of_delete;++j)
                judge_use.at(j)=0;
            for (int j=num_of_delete;j<s_size;++j)
                judge_use.at(j)=1;
            do
            {
                if (judge_valid(s,judge_use,s_size))
                {
                    string temp="";
                    for (int j=0;j<s_size;++j)
                        if (judge_use.at(j))
                            temp+=s.at(j);
                    answer.insert(temp);
                    //因为是要求删除最小数量的括号，我们从只删除0个开始
                    //即只要字符串有效了，即找到了删除最小数量的括号，所以要跳出for了，因为删除更多括号没有意义
                    i=s_size;
                }
            }while(next_permutation(judge_use.begin(),judge_use.end()));
            ++num_of_delete;
        }
        if (answer.empty())
            return {""};
        return vector<string>(answer.begin(),answer.end());
    }
    bool judge_valid(const string &s,const vector<int>& judge_use,const int & s_size)
    {
        int left=0,right=0;
        for (int i=0;i<s_size;++i)
            if (judge_use.at(i))
            {
                if (s.at(i)=='(')
                    ++left;
                else if (s.at(i)==')')
                {
                    if (left>0)
                        --left;
                    else
                        ++right;
                }
            }
        return left==0 && right==0;
    }
};
