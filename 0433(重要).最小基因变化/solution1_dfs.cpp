class Solution {
    int size=8;
    unordered_set<string> pre;
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int ans=INT_MAX;
        pre.clear();
        pre.insert(start);
        dfs(start,end,ans,bank,0);
        return ans==INT_MAX ? -1 : ans;
    }
    void dfs(string cur,const string &target,int &ans,vector<string>& bank,int step)
    {
        if (cur==target)
        {
            if (step<ans)
                ans=step;
            return;
        }
        for (string &i:bank)
        {
            if (pre.find(i)!=pre.end())
                continue;
            int diff=0;
            for (int j=0;j<size;++j)
                if (i.at(j)!=cur.at(j))
                    ++diff;
            if (diff==1)
            {
                pre.insert(i);
                dfs(i,target,ans,bank,step+1);
                pre.erase(pre.find(i));
            }
        }
    }
};
