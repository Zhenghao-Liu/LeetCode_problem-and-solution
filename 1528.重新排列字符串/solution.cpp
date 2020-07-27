class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans=s;
        for (int i=0;i<s.size();++i)
            ans.at(indices.at(i))=s.at(i);
        return ans;
    }
};
