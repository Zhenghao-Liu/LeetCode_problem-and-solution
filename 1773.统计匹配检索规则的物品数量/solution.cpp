// ruleKey == "type" 且 ruleValue == typei 。
// ruleKey == "color" 且 ruleValue == colori 。
// ruleKey == "name" 且 ruleValue == namei 。
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string v) {
        unordered_map<string,int> ump;
        ump["type"]=0;
        ump["color"]=1;
        ump["name"]=2;
        int idx=ump[ruleKey];
        int ans=0;
        for (vector<string> &i:items) {
            if (i.at(idx)==v) {
                ans++;
            }
        }
        return ans;
    }
};
