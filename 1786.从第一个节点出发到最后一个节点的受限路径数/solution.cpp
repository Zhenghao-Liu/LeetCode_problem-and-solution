/*
 * 首先迪杰斯特拉求出路径数图
 * 因为只能从高往低，所以排序后从高往低累加即可
 */
typedef long long ll;
ll mod=1e9+7;
const int MAXN=2e4+1;
ll vis[MAXN];
typedef pair<int,ll> pii;
class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        memset(vis,0,sizeof(ll)*(n+1));
        vector<ll> dis(n+1,INT_MAX);
        vector<vector<pii>> edg(n+1);
        for (vector<int> &i:edges) {
            int u=i.at(0),v=i.at(1),val=i.at(2);
            edg.at(u).push_back({v,val});
            edg.at(v).push_back({u,val});
        }
        auto func=[](const pii &A,const pii &B){
            return A.second>B.second;
        };
        priority_queue<pii,vector<pii>,decltype(func)> pq(func);
        pq.push({n,0});
        dis.at(n)=0;
        while (!pq.empty()) {
            auto [cur,val]=pq.top();
            pq.pop();
            if (vis[cur]==1) {
                continue;
            }
            vis[cur]=1;
            for (auto &[nxt,nxtVal]:edg.at(cur)) {
                if (dis.at(nxt)>val+nxtVal) {
                    dis.at(nxt)=val+nxtVal;
                    pq.push({nxt,val+nxtVal});
                }
            }
        }
        vector<int> idx(n+1);
        for (int i=0;i<=n;i++) {
            idx.at(i)=i;
        }
        sort(idx.begin(),idx.end(),[&dis](const int &A,const int &B){
            return dis.at(A)>dis.at(B);
        });
        vector<ll> ans(n+1);
        ans.at(1)=1;
        for (int i=0;i<=n;i++) {
            int ii=idx.at(i);
            for (auto &[nxt,tmp]:edg.at(ii)) {
                if (dis.at(ii)>dis.at(nxt)) {
                    ans.at(nxt)+=ans.at(ii);
                    ans.at(nxt)%=mod;
                }
            }
        }
        return ans.at(n)%mod;
    }
};
