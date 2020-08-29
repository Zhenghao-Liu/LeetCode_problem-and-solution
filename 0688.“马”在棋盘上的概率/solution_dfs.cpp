/*
* dp[i][j][step]表示在棋盘[i][j]位置，走step步不会出界的概率
* 显然初始化dp[i][j][0]=1因为走0步，即一定不出界，所以概率为1
* dp[i][j][step]依赖于dp[ii][jj][step-1]/8.0
  因为每多走一步，总数都是乘8，即题目要求走K次，最后的分母是8^K
  所以概率要/8.0
* 最后答案就是dp[r][c][K]
*/
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
        return get_dp(N,r,c,K);
    }
    double get_dp(int N,int x,int y,int step)
    {
        if (step==0)
            return 1.0;
        if (dp[x][y][step]>EPSILON)
            return dp[x][y][step];
        for (int k=0;k<8;++k)
        {
            int xx=x+dir_x[k];
            int yy=y+dir_y[k];
            if (xx>=0 && xx<N && yy>=0 && yy<N)
                dp[x][y][step]+=get_dp(N,xx,yy,step-1)/8.0;
        }
        return dp[x][y][step];
    }
};
