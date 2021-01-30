const int UP=10;
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans=0;
        unordered_map<int,int> ump;
        for (vector<int> &i:dominoes) {
            int a=i.at(0);
            int b=i.at(1);
            if (a>b) {
                swap(a,b);
            }
            int cur=a*UP+b;
            auto p=ump.find(cur);
            if (p!=ump.end()) {
                ans+=(*p).second;
            }
            ump[cur]++;
        }
        return ans;
    }
};
