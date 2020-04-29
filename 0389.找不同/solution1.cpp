class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> ans(26,0);
        for (char &i:s)
            ++ans.at(i-'a');
        for (char &i:t)
        {
            --ans.at(i-'a');
            if (ans.at(i-'a')<0)
                return i;
        }
        return 0;
    }
};
