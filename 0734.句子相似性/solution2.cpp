class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int s1=sentence1.size(),s2=sentence2.size();
        if (s1!=s2)
            return false;
        unordered_set<string> helper;
        for (vector<string> &i:similarPairs)
        {
            helper.insert(i.at(0)+"#"+i.at(1));
            helper.insert(i.at(1)+"#"+i.at(0));
        }
        for (int i=0;i<s1;++i)
        {
            if (sentence1.at(i)==sentence2.at(i))
                continue;
            else
            {
                if (helper.find(sentence1.at(i)+"#"+sentence2.at(i))!=helper.end())
                    continue;
                if (helper.find(sentence2.at(i)+"#"+sentence1.at(i))!=helper.end())
                    continue;
                return false;
            }
        }
        return true;
    }
};
