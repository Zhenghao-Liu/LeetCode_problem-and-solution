class Solution {
    vector<bool> cache;
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> table(n);
        for (vector<int> &i:prerequisites)
            table[i[0]].push_back(i[1]);
        int queries_size=queries.size();
        vector<bool> ans;
        for (int i=0;i<queries_size;++i)
        {
            cache=vector<bool>(n,false);
            ans.push_back(dfs(table,queries[i][0],queries[i][1]));
        }
        return ans;
    }
    bool dfs(vector<vector<int>> &table,int cur,const int &target)
    {
        if (cache[cur])
            return false;
        cache.at(cur)=true;
        if (cur==target)
        {
            return true;
        }
        bool judge=false;
        for (int &i:table[cur])
        {
            judge=judge || dfs(table,i,target);
            if (judge)
                return true;
        }
        return false;
    }
};
