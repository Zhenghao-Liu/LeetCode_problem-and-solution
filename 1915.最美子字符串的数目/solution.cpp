// 二进制0 1表示奇偶
typedef long long ll;
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int,int> ump;
        int cur=0;
        ll ans=0;
        ump[0]=1;
        vector<int> tar;
        tar.reserve(11);
        tar.push_back(0);
        for (int i=0;i<10;i++) {
            tar.push_back(1<<i);
        }
        for (char i:word) {
            cur^=1<<(i-'a');
            for (int j:tar) {
                auto p=ump.find(j^cur);
                if (p!=ump.end()) {
                    ans+=p->second;
                }
            }
            ump[cur]++;
        }
        return ans;
    }
};