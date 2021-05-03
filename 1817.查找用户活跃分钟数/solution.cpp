class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k);
        unordered_set<int> ust;
        sort(logs.begin(),logs.end());
        int lst=logs.at(0).at(0);
        int sz=logs.size();
        for (int i=0;i<=sz;i++) {
            if (i==sz) {
                ans.at(ust.size()-1)++;
                continue;
            }
            if (logs.at(i).at(0)!=lst) {
                ans.at(ust.size()-1)++;
                lst=logs.at(i).at(0);
                ust.clear();
            }
            ust.insert(logs.at(i).at(1));
        }
        return ans;
    }
};