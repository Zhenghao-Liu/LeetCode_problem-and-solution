class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> mask;
        for (vector<string> &i:paths)
            mask.insert({i.at(0),i.at(1)});
        string ans;
        dfs(mask,paths.at(0).at(0),ans);
        return ans;
    }
    void dfs(unordered_map<string,string> &mask,string start,string & ans)
    {
        if (mask.find(start)==mask.end())
        {
            ans=start;
            return;
        }
        dfs(mask,mask.at(start),ans);
    }
};
