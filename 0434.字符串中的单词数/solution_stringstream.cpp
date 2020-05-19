class Solution {
public:
    int countSegments(string s) {
        stringstream ss;
        ss << s;
        string temp;
        int ans=0;
        while (ss >> temp)
            ++ans;
        return ans;
    }
};
