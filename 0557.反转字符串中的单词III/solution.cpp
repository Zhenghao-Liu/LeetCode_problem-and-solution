class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
            return "";
        stringstream ss;
        ss << s;
        string ans;
        string words;
        while (ss >> words)
        {
            reverse(words.begin(),words.end());
            ans+=words+" ";
        }
        ans.pop_back();
        return ans;
    }
};
