// 同样的方法，但是判断两个节点是否相连可以采用哈希的方式，但是会卡常，所以一定要剪枝
const int MAXN=400+1;
int cnt[MAXN];
class Solution {
    unordered_set<int> ust;
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        memset(cnt,0,sizeof(cnt));
        ust.clear();
        for (vector<int> &i:edges) {
            int a=i.at(0),b=i.at(1);
            if (a>b) {
                swap(a,b);
            }
            ust.insert(hash(a,b));
            cnt[a]++;
            cnt[b]++;
        }
        int ans=INT_MAX;
        for (int i=1;i<=n;i++) {
            for (int j=i+1;j<=n;j++) {
                if (ust.find(hash(i,j))!=ust.end()) {
                    for (int k=j+1;k<=n;k++) {
                        if (ust.find(hash(i,k))!=ust.end() && ust.find(hash(j,k))!=ust.end()) {
                            int cur=0;
                            cur+=cnt[i]-2;
                            cur+=cnt[j]-2;
                            cur+=cnt[k]-2;
                            ans=min(ans,cur);
                        }
                    }
                }
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
    int hash(int a,int b) {
        return a*1000+b;
    }
};
