class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (string &i:words)
            for (string &j:words)
                if (i!=j && j.find(i)!=string::npos)
                {
                    ans.push_back(i);
                    break;
                }
        return ans;
    }
};
