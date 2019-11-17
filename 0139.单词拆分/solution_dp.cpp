class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int s_size=s.size();
        vector<bool> dp(s_size+1,false);
        dp.at(0)=true;
        for (int i=1;i<=s_size;++i)
            for (int j=i-1;j>=0;--j)
                if (dp.at(j) && find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end())
                {
                    dp.at(i)=true;
                    break;
                }
        return dp.at(s_size);
    }
};
