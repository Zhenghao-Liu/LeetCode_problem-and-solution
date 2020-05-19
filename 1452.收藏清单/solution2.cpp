class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int size=favoriteCompanies.size();
        for (vector<string> &i:favoriteCompanies)
            sort(i.begin(),i.end());
        vector<int> ans;
        for (int i=0;i<size;++i)
        {
            bool judge=false;
            for (int j=0;j<size;++j)
            {
                if (i==j)
                    continue;
                if (includes(favoriteCompanies.at(j).begin(),favoriteCompanies.at(j).end(),favoriteCompanies.at(i).begin(),favoriteCompanies.at(i).end()))
                    judge=true;
                if (judge)
                    break;
            }
            if (!judge)
                ans.push_back(i);
        }
        return ans;
    }
};
