class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> change;
        unordered_map<char,char> rechange;
        int size=s.size();
        for (int i=0;i<size;++i)
            if (change.find(s.at(i))==change.end())
            {
                if (rechange.find(t.at(i))==rechange.end())
                {
                    change.insert({s.at(i),t.at(i)});
                    rechange.insert({t.at(i),s.at(i)});
                }
                else if (s.at(i)!=t.at(i))
                    return false;
            } 
            else if (change.at(s.at(i))!=t.at(i))
                return false;
        return true;
    }
};
