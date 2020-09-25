class Solution {
    unordered_set<string> memo;
    int ans;
    int size;
public:
    int maxUniqueSplit(string s) {
        size=s.size();
        ans=0;
        memo.clear();
        dfs(s,0);
        return ans;
    }
    void dfs(string &s,int start)
    {
        //剪枝:假设后面最优情况，每个字母都可以唯一拆分，还是没ans大，也就没必要回溯了
        if ((int)memo.size()+(size-start)<=ans)
            return;
        if (start==size)
        {
            ans=max(ans,(int)memo.size());
            return;
        }
        string t;
        for (int j=start;j<size;++j)
        {
            t+=s.at(j);
            if (memo.find(t)==memo.end())
            {
                memo.insert(t);
                dfs(s,j+1);
                memo.erase(t);
            }
        }
        return;
    }
};
