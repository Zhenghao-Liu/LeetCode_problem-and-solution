//记录与之相邻的边数，以及是否与别的点相连，然后枚举所有组合即可
const int MAXN=100;
int has[MAXN][MAXN];
int cnt[MAXN];
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        memset(has,0,sizeof(has));
        memset(cnt,0,sizeof(cnt));
        for (vector<int> &i:roads)
        {
            ++cnt[i.at(0)];
            ++cnt[i.at(1)];
            has[i.at(0)][i.at(1)]=1;
            has[i.at(1)][i.at(0)]=1;
        }
        int ans=0;
        for (int i=0;i<n;++i)
            for (int j=i+1;j<n;++j)
            {
                int c=cnt[i]+cnt[j];
                if (has[i][j]==1)
                    --c;
                ans=max(ans,c);
            }
        return ans;
    }
};
