//tle的边缘试探
class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        if (sentence.empty())
            return 0;
        if (dictionary.empty())
            return sentence.size();
        unordered_set<string> dict(dictionary.begin(),dictionary.end());
        int sentence_size=sentence.size();
        vector<int> dp(sentence_size);
        for (int i=0;i<sentence_size;++i)
        {
            if (i!=0)
                dp.at(i)=dp.at(i-1)+1;
            else
                dp.at(i)=1;
            for (int j=0;j<=i;++j)
                if (dict.find(sentence.substr(j,i-j+1))!=dict.end())
                {
                    if (j-1>=0)
                        dp.at(i)=min(dp.at(i),dp.at(j-1));
                    else
                    {
                        dp.at(i)=0;
                        break;
                    }
                }
        }
        return dp.back();
    }
};
