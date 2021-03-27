class Solution {
public:
    int secondHighest(string s) {
        map<char,int> mp;
        for (char i:s) {
            if (i>='0' && i<='9') {
                mp[i-'0']++;
            }
        }
        if (mp.size()<2) {
            return -1;
        }
        auto ans=mp.end();
        ans--;
        ans--;
        return ans->first;
    }
};