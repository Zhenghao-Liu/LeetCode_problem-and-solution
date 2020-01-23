class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map_s,map_t;
        if (s.size()!=t.size())
            return false;
        int size=s.size();
        for (int i=0;i<size;++i)
        {
            ++map_s[s.at(i)];
            ++map_t[t.at(i)];
        }
        for (auto& i:map_s)
            if (map_t.find(i.first)==map_t.end() || i.second!=map_t.at(i.first))
                return false;
        return true;
    }
};
