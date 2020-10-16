//模拟即可
class Solution {
    unordered_map<string,vector<char>> dict;
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        dict.clear();
        for (string &i:allowed)
            dict[i.substr(0,2)].push_back(i.at(2));
        return dfs(bottom);
    }
    bool dfs(string &bottom)
    {
        int bottom_size=bottom.size();
        if (bottom_size==1)
            return true;
        vector<string> nxt{""};
        vector<string> tmp;
        string key;
        for (int i=1;i<bottom_size;++i)
        {
            key.clear();
            key+=bottom.at(i-1);
            key+=bottom.at(i);
            int nxt_size=nxt.size();
            tmp.clear();
            if (dict.find(key)==dict.end())
                return false;
            for (char c:dict.at(key))
                for (int j=0;j<nxt_size;++j)
                    tmp.push_back(nxt.at(j)+c);
            nxt=tmp;
        }
        for (string &i:nxt)
            if (dfs(i))
                return true;
        return false;
    }
};
