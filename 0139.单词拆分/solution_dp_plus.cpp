/*
* 进一步优化版本
* 采用unordered_set减低find的复杂度
* 且记录下wordDict中最长单词长度max_dict_size
* 当新子串的长度大于max_dict_size则必然查找失败，即跳出循环
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int s_size=s.size();
        vector<bool> dp(s_size+1,false);
        unordered_set<string> wordDict_set(wordDict.begin(),wordDict.end());
        int max_dict_size=0;
        for (string str:wordDict_set)
            max_dict_size=max(max_dict_size,int(str.size()));
        dp.at(0)=true;
        for (int i=1;i<=s_size;++i)
            for (int j=i-1;j>=0 && j>=i-max_dict_size;--j)
                if (dp.at(j) && wordDict_set.find(s.substr(j,i-j))!=wordDict_set.end())
                {
                    dp.at(i)=true;
                    break;
                }
        return dp.at(s_size);
    }
};
