/*
 * 每个元素只有左边一个元素右边元素
 * 但是有两个特例，就是最左边的元素和最右边的元素，他们只有一个相邻元素
 * 把每个位置元素当成图中的一个节点，那么最左边的元素和最右边的元素的度为1，其他剩下的点度为2
 * 选择一个度为1的节点开始一路往下推即可，因为最左边元素开始或者最右边元素开始都是满足题目要求的，任意即可
 */
const int INF=0x3f3f3f3f;
typedef pair<int,int> pii;
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adj) {
        unordered_map<int,pii> ump;
        for (vector<int> &i:adj) {
            int a=i.at(0),b=i.at(1);
            auto p=ump.find(a);
            if (p==ump.end()) {
                ump[a]={b,INF};
            } else {
                (*p).second.second=b;
            }
            p=ump.find(b);
            if (p==ump.end()) {
                ump[b]={a,INF};
            } else {
                (*p).second.second=a;
            }
        }
        int sz=adj.size()+1;
        vector<int> ans;
        ans.reserve(sz);
        int beg=INF;
        for (auto &i:ump) {
            if (i.second.second==INF) {
                ans.push_back(i.first);
                beg=i.first;
                break;
            }
        }
        while (ans.size()<sz) {
            int st=ans.back();
            int nxt=INF;
            auto p=ump.find(st);
            if ((*p).second.first!=INF && (*p).second.first!=beg) {
                nxt=(*p).second.first;
                (*p).second.first=INF;
            } else {
                nxt=(*p).second.second;
                (*p).second.second=INF;
            }
            beg=st;
            ans.push_back(nxt);
        }
        return ans;
    }
};
