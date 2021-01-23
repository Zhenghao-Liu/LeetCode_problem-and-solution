const int MAXN=1e5;
int vis[MAXN];
class Solution {
    vector<vector<int>> edge;
    vector<int> sor;
    vector<int> tar;
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        memset(vis,0,sizeof(vis));
        int size=source.size();
        edge=vector<vector<int>>(size);
        for (vector<int> &i:allowedSwaps) {
            int a=i.at(0),b=i.at(1);
            edge.at(a).push_back(b);
            edge.at(b).push_back(a);
        }
        sor.reserve(size);
        tar.reserve(size);
        int ans=0;
        for (int i=0;i<size;i++) {
            if (vis[i]==1) {
                continue;
            }
            bfs(i,source,target);
            ans+=diff(sor,tar);
        }
        return ans;
    }
    void bfs(int st,vector<int> &s,vector<int> &t) {
        queue<int> que;
        que.push(st);
        vis[st]=1;
        sor.clear();
        tar.clear();
        sor.push_back(s.at(st));
        tar.push_back(t.at(st));
        while (!que.empty()) {
            int size=que.size();
            for (int i=0;i<size;i++) {
                int cur=que.front();
                que.pop();
                for (int nxt:edge.at(cur)) {
                    if (vis[nxt]==0) {
                        vis[nxt]=1;
                        que.push(nxt);
                        sor.push_back(s.at(nxt));
                        tar.push_back(t.at(nxt));
                    }
                }
            }
        }
    }
    int diff(vector<int> &a,vector<int> &b) {
        int size=a.size();
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int p1=0,p2=0;
        int same=0;
        while (p1<size && p2<size) {
            int aa=a.at(p1),bb=b.at(p2);
            if (aa==bb) {
                p1++;
                p2++;
                same++;
            } else if (aa<bb) {
                p1++;
            } else {
                p2++;
            }
        }
        return size-same;
    }
};
