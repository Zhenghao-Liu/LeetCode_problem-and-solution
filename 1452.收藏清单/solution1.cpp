class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int size=favoriteCompanies.size();
        vector<unordered_set<string>> helper(size);
        for (int i=0;i<size;++i)
        {
            for (string &j:favoriteCompanies.at(i))
                helper.at(i).insert(j);
        }
        vector<int> ans;
        for (int i=0;i<size;++i)
        {
            bool judge;
            for (int j=0;j<size;++j)
            {
                if (j==i)
                    continue;
                judge=false;
                for (string &k:favoriteCompanies.at(i))
                    if (helper.at(j).find(k)==helper.at(j).end())
                        judge=true;
                if (!judge)
                    break;
            }
            if (judge)
                ans.push_back(i);
        }
        return ans;
    }
};
