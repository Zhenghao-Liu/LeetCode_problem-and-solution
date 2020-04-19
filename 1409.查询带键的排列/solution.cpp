class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        if (queries.empty())
            return {};
        list<int> helper;
        for (int i=1;i<=m;++i)
            helper.push_back(i);
        vector<int> ans;
        ans.reserve(queries.size());
        for (int &i:queries)
        {
            list<int>::iterator p;
            int index;
            for (p=helper.begin(),index=0;p!=helper.end();++p,++index)
                if (*p==i)
                    break;
            ans.push_back(index);
            helper.erase(p);
            helper.push_front(i);
        }
        return ans;
    }
};
