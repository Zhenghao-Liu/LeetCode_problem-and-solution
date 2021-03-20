class Solution {
public:
    string removeDuplicates(string S) {
        vector<char> ans;
        ans.reserve(S.size());
        for (char i:S) {
            ans.push_back(i);
            int sz=ans.size();
            while (sz>=2 && ans.at(sz-1)==ans.at(sz-2)) {
                ans.pop_back();
                ans.pop_back();
                sz-=2;
            }
        }
        return string(ans.begin(),ans.end());
    }
};
