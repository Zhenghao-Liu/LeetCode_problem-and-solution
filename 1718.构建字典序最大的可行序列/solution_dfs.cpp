// 数据量不大，那就贪心的去dfs
const int MAXN=21;
int vis[MAXN];
class Solution {
    int UP;
public:
    vector<int> constructDistancedSequence(int n) {
        int size=n*2-1;
        vector<int> ans(size,-1);
        memset(vis,0,sizeof(vis));
        UP=n;
        dfs(ans,0);
        return ans;
    }
    bool dfs(vector<int> & ans,int idx) {
        if (idx==ans.size()) {
            return true;
        }
        if (ans.at(idx)!=-1) {
            return dfs(ans,idx+1);
        }
        for (int i=UP;i>=1;i--) {
            if (vis[i]==1) {
                continue;
            }
            int nxt=idx+i;
            if (i!=1 && nxt>=ans.size()) {
                continue;
            }
            if (i!=1 && ans.at(nxt)!=-1) {
                continue;
            }
            ans.at(idx)=i;
            vis[i]=1;
            if (i!=1) {
                ans.at(nxt)=i;
            }
            if (dfs(ans,idx+1)) {
                return true;
            }
            vis[i]=0;
            ans.at(idx)=-1;
            if (i!=1) {
                ans.at(nxt)=-1;
            }
        }
        return false;
    }
};
