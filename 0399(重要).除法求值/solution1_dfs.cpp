class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<double,string>>> dict;
        int values_size=values.size();
        for (int i=0;i<values_size;++i)
        {
            dict[equations.at(i).at(0)].push_back({values.at(i),equations.at(i).at(1)});
            dict[equations.at(i).at(1)].push_back({1.0/values.at(i),equations.at(i).at(0)});
        }
        vector<double> ans;
        unordered_set<string> cache;
        for (vector<string> &i:queries)
        {
            if (dict.find(i.at(0))==dict.end() || dict.find(i.at(1))==dict.end())
                ans.push_back(-1);
            else if (i.at(0)==i.at(1))
                ans.push_back(1);
            else
            {
                cache.clear();
                cache.insert(i.at(0));
                if (dfs(dict,cache,i.at(0),i.at(1),1.0,ans))
                    continue;
                else
                    ans.push_back(-1.0);
            }
        }
        return ans;
    }
    bool dfs(unordered_map<string,vector<pair<double,string>>> &dict,unordered_set<string> &cache,string start,const string &target,double cur,vector<double> & ans)
    {
        if (start==target)
        {
            ans.push_back(cur);
            return true;
        }
        for (pair<double,string> &i:dict.at(start))
        {
            if (cache.find(i.second)==cache.end())
            {
                cache.insert(i.second);
                if (dfs(dict,cache,i.second,target,cur*i.first,ans))
                    return true;
            }
        }
        return false;
    }
};
