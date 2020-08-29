//dfs的填表形式
int dir_x[]={-2,-2,-1,-1,1,1,2,2};
int dir_y[]={-1,1,-2,2,-2,2,-1,1};
const double EPSILON=1e-6;
const int MAXN=25;
const int MAXK=101;
double dp[MAXN][MAXN][MAXK];
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        memset(dp,0,sizeof(dp));
        for (int i=0;i<N;++i)
            for (int j=0;j<N;++j)
                dp[i][j][0]=1.0;
        for (int k=1;k<=K;++k)
            for (int i=0;i<N;++i)
                for (int j=0;j<N;++j)
                {
                    for (int t=0;t<8;++t)
                    {
                        int xx=i+dir_x[t];
                        int yy=j+dir_y[t];
                        if (xx>=0 && xx<N && yy>=0 && yy<N)
                            dp[i][j][k]+=dp[xx][yy][k-1]/8.0;
                    }
                }
        return dp[r][c][K];
    }
};
