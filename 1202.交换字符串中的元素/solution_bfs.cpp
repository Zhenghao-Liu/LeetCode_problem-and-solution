const int MAXN=1e5;
int vis[MAXN];
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        memset(vis,0,sizeof(vis));
        int size=s.size();
        vector<vector<int>> edge(size);
        for (vector<int> &i:pairs) {
            int a=i.at(0);
            int b=i.at(1);
            edge.at(a).push_back(b);
            edge.at(b).push_back(a);
        }
        vector<int> idx;
        vector<char> val;
        idx.reserve(size);
        val.reserve(size);
        for (int i=0;i<size;i++) {
            if (vis[i]==1) {
                continue;
            }
            vis[i]=1;
            queue<int> que;
            que.push(i);
            idx.clear();
            idx.push_back(i);
            val.clear();
            val.push_back(s.at(i));
            while (!que.empty()) {
                int len=que.size();
                for (int j=0;j<len;j++) {
                    int cur=que.front();
                    que.pop();
                    for (int nxt:edge.at(cur)) {
                        if (vis[nxt]==1) {
                            continue;
                        }
                        vis[nxt]=1;
                        idx.push_back(nxt);
                        val.push_back(s.at(nxt));
                        que.push(nxt);
                    }
                }
            }
            sort(idx.begin(),idx.end());
            sort(val.begin(),val.end());
            int len=idx.size();
            for (int j=0;j<len;j++) {
                s.at(idx.at(j))=val.at(j);
            }
        }
        return s;
    }
};
