// 400数据量，可以n3的去枚举即可
const int MAXN=400+1;
int cnt[MAXN];
bool con[MAXN][MAXN];
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        memset(cnt,0,sizeof(cnt));
        memset(con,false,sizeof(con));
        for (vector<int> &i:edges) {
            int a=i.at(0),b=i.at(1);
            if (a>b) {
                swap(a,b);
            }
            con[a][b]=true;
            cnt[a]++;
            cnt[b]++;
        }
        int ans=INT_MAX;
        for (int i=1;i<=n;i++) {
            for (int j=i+1;j<=n;j++) {
                // 剪枝
                if (con[i][j]) {
                    for (int k=j+1;k<=n;k++) {
                        if (helper(i,j,k)) {
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
    bool helper(int a,int b,int c) {
        if (con[a][b] && con[b][c] && con[a][c]) {
            return true;
        } 
        return false;
    }
};
