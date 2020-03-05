//简化了stack版本
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int s_size=s.size();
        string answer;
        for (int i=0;i<s_size;++i)
        {
            if (answer.find(s.at(i))!=string::npos)
                continue;
            while (!answer.empty() && s.at(i)<answer.back() && s.find(answer.back(),i+1)!=string::npos)
                answer.pop_back();
            answer.push_back(s.at(i));
        }
        return answer;
    }
};
