//既然哈希表查找字符串过于麻烦，自己写哈希映射把string映射成long long
class Solution {
    int base=INT_MAX;
    int hash_helper=41;
public:
    int respace(vector<string>& dictionary, string sentence) {
        if (sentence.empty())
            return 0;
        if (dictionary.empty())
            return sentence.size();
        unordered_set<long long> dict;
        for (string &i:dictionary)
            dict.insert(my_hash(i));
        int sentence_size=sentence.size();
        vector<int> dp(sentence_size);
        for (int i=0;i<sentence_size;++i)
        {
            if (i!=0)
                dp.at(i)=dp.at(i-1)+1;
            else
                dp.at(i)=1;
            long long hash=0;
            for (int j=i;j>=0;--j)
            {
                hash=(hash*hash_helper%base+sentence.at(j)-'a'+1)%base;
                if (dict.find(hash)!=dict.end())
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
        }
        return dp.back();
    }
    long long my_hash(string &s)
    {
        long long ans=0;
        for (int i=s.size()-1;i>=0;--i)
            ans=(ans*hash_helper%base-'a'+s.at(i)+1)%base;
        return ans;
    }
};
