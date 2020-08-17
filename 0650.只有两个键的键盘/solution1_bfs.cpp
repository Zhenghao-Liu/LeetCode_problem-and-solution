//既然试求变化的最小次数，可以bfs
typedef pair<int,int> pii;
class Solution {
public:
    int minSteps(int n) {
        //first存当前字符串，second存剪贴板字符数量
        queue<pii> helper;
        helper.push({1,0});
        set<pii> path;
        path.insert({1,0});
        int ans=-1;
        while (!helper.empty())
        {
            int size=helper.size();
            ++ans;
            for (int i=0;i<size;++i)
            {
                auto [cur,paste]=helper.front();
                helper.pop();
                if (cur==n)
                    return ans;
                pii new_insert;
                new_insert={cur,cur};
                if (path.find(new_insert)==path.end())
                {
                    helper.push(new_insert);
                    path.insert(new_insert);
                }
                if (cur+paste<=n)
                {
                    new_insert={cur+paste,paste};
                    if (path.find(new_insert)==path.end())
                    {
                        helper.push(new_insert);
                        path.insert(new_insert);
                    }
                }
            }
        }
        //无效return
        return -1;
    }
};
