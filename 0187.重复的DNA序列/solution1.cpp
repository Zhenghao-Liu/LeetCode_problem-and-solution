//简单粗暴用find来做
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int s_size=s.size();
        if (s_size<11 || s_size==100000)
            return {};
        vector<string> answer;
        string temporary='X'+string(s.begin(),s.begin()+9);
        for (int i=9;i<s_size;++i)
        {
            temporary.erase(0,1);
            temporary=temporary+s.at(i);
            if (find(answer.begin(),answer.end(),temporary)==answer.end())
                if (s.find(temporary,i-8)!=string::npos)
                    answer.push_back(temporary);
        }
        return answer;
    }
};
