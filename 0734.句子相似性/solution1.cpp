class Solution {
    unordered_map<string,unordered_set<string>> helper;
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int s1=sentence1.size(),s2=sentence2.size();
        if (s1!=s2)
            return false;
        helper.clear();
        for (vector<string> &i:similarPairs)
        {
            helper[i.at(0)].insert(i.at(1));
            helper[i.at(1)].insert(i.at(0));
        }
        for (int i=0;i<s1;++i)
        {
            if (sentence1.at(i)==sentence2.at(i))
                continue;
            else
            {
                if (judge(sentence1.at(i),sentence2.at(i)) || judge(sentence2.at(i),sentence1.at(i)))
                    continue;
                return false;
            }
        }
        return true;
    }
    bool judge(string s1,string s2)
    {
        if (helper.find(s1)==helper.end())
            return false;
        if (helper.at(s1).find(s2)==helper.at(s1).end())
            return false;
        return true;
    }
};
