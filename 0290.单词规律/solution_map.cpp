class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> dict;
        string temp_str="";
        for (char &i:str)
            if (i!=' ')
                temp_str+=i;
            else
            {
                dict.push_back(temp_str);
                temp_str="";
            }
        dict.push_back(temp_str);
        unordered_map<string,char> mask_s_c;
        unordered_map<char,string> mask_c_s;
        int pattern_size=pattern.size();
        if (dict.size()!=pattern_size)
            return false;
        for (int i=0;i<pattern_size;++i)
        {
            bool judge_s_c=(mask_s_c.count(dict.at(i))==0);
            bool judge_c_s=(mask_c_s.count(pattern.at(i))==0);
            if (judge_s_c && judge_c_s)
            {
                mask_s_c.insert({dict.at(i),pattern.at(i)});
                mask_c_s.insert({pattern.at(i),dict.at(i)});
            }
            else if (!judge_s_c && mask_s_c.at(dict.at(i))!=pattern.at(i))
                return false;
            else if (!judge_c_s && mask_c_s.at(pattern.at(i))!=dict.at(i))
                return false;
        }
        return true;
    }
};
