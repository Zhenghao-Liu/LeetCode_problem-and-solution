//先采用上一题走一次，如果不能构成完整s那么就没有意义去回溯了
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int s_size=s.size(),max_wordDict_size=0;
        for (string &str:wordDict)
            if (str.size()>max_wordDict_size)
                max_wordDict_size=str.size();
        unordered_set<string> wordDict_set(wordDict.begin(),wordDict.end());
        vector<bool> dp(s_size+1,false);
        dp.at(0)=true;
        for (int i=1;i<=s_size;++i)
            for (int j=i-1;j>=0 && j>=i-max_wordDict_size;--j)
                if (dp.at(j) && wordDict_set.find(s.substr(j,i-j))!=wordDict_set.end())
                {
                    dp.at(i)=true;
                    break;
                }
        vector<string> answer;
        if (!dp.at(s_size))
            return answer;
        get_wordBreak(s,wordDict_set,s_size,max_wordDict_size,answer,0,"");
        for (string &str:answer)
            str.erase(0,1);
        return answer;
    }
    void get_wordBreak(const string &s,unordered_set<string>& wordDict_set,const int & s_size,const int & max_wordDict_size,vector<string>& answer,int left,string temporary_ans)
    {
        if (left==s_size)
        {
            answer.push_back(string(temporary_ans));
            return;
        }
        string temporary;
        for (int i=left;i<s_size && i-left<max_wordDict_size;++i)
        {
            temporary=s.substr(left,i-left+1);
            if (wordDict_set.find(temporary)!=wordDict_set.end())
                get_wordBreak(s,wordDict_set,s_size,max_wordDict_size,answer,i+1,temporary_ans+" "+temporary);
        }
    }
};
