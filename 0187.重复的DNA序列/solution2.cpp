//记录下每个子串出现次数，这样复杂度为O(N)
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int s_size=s.size();
        if (s_size<11)
            return {};
        vector<string> answer;
        unordered_map<string,int> substr;
        string temporary;
        for (int i=0;i<s_size-9;++i)
        {
            temporary=s.substr(i,10);
            ++substr[temporary];
            if (substr.at(temporary)==2)
                answer.push_back(temporary);
        }
        return answer;
    }
};
