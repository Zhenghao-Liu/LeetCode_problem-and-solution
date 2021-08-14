class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> ump;
        for (char i:s) {
            ump[i]++;
        }
        int ans=-1;
        for (auto &i:ump) {
            if (ans==-1) {
                ans=i.second;
            } else if (i.second!=ans){
                return false;
            }
        }
        return true;
    }
};