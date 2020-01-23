//将每个运算符的左右两边分为两个部分，分别计算他们的值（也就相当于给左右两边分别加括号），这样就可以得到所有组合的结果
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int input_size=input.size();
        if (input_size==0)
            return {};
        bool judge_operator=false;
        vector<int> answer;
        for (int i=0;i<input_size;++i)
        {
            if (input.at(i)>='0')
                continue;
            judge_operator=true;
            vector<int> left_part=diffWaysToCompute(string(input.begin(),input.begin()+i));
            vector<int> right_part=diffWaysToCompute(string(input.begin()+i+1,input.end()));
            int result;
            char operator_i=input.at(i);
            for (int &j:left_part)
                for (int &k:right_part)
                {
                    switch(operator_i)
                    {
                        case '+': result=j+k; break;
                        case '-': result=j-k; break;
                        case '*': result=j*k; break;
                    }
                    answer.push_back(result);
                }
        }
        if (!judge_operator)
            answer.push_back(stoi(input));
        return answer;
    }
};
