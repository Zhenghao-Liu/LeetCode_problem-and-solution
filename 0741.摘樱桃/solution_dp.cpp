/*
 * 既然是从左上角走到右下角再走到右下角，且因为矩形大小给定，所以走的总步长一定是2*(N-1)
 * 所以可以反过来考虑成两个人同时从左上角到右下角，且当前走过的步数相同
 * 设到达了[r][c]则r+c=step，两个人分别到达了[r1][c1]和[r2][c2]，则r1+c1=r2+c2
 * 所以只用三个变量就可以确定第四个即r2=r1+c1-c2
 * dp[r1][c1][c2]表示从[r1][c1]和[r2][c2]到达右下角[N-1][N-1]的最多樱桃数
 * 初始状态dp[N-1][N-1][N-1]=grid[N-1][N-1]
 * 最终答案是dp[0][0][0]，且最少也是0个樱桃
 * 转移dp[r1][c1][c2]=
   1. grid[r1][c1]和grid[r2][c2]本身的樱桃数，且注意若是同一个位置需要去重
   2. 根据人1和人2下一步是向右还是向下可以分成4种情况，取最大值
      1)人1右，人2右：dp[r1][c1+1][c2+1]
      2)人1右，人2下：dp[r1][c1+1][c2]
      3)人1下，人2下：dp[r1+1][c1][c2]
      4)人1下，人2右：dp[r1+1][c1][c2+1]
 * 因为是求最大的樱桃即max求值，所以无效状态设一个较小值
 */
const int MAXN=50;
int dp[MAXN][MAXN][MAXN];
class Solution {
    int INFS=0xc0c0c0c0;
    int N;
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,0xc0,sizeof(dp));
        N=grid.size();
        dp[N-1][N-1][N-1]=grid.at(N-1).at(N-1);
        return max(0,get_dp(0,0,0,grid));
    }
    int get_dp(int r1,int c1,int c2,vector<vector<int>> & grid)
    {
        int r2=r1+c1-c2;
        if (!(r1>=0 && r1<N && c1>=0 && c1<N) || !(r2>=0 && r2<N && c2>=0 && c2<N))
            return INFS;
        if (grid.at(r1).at(c1)==-1 || grid.at(r2).at(c2)==-1)
            return INFS;
        if (dp[r1][c1][c2]!=INFS)
            return dp[r1][c1][c2];
        int ans=0;
        if (r1==r2 && c1==c2)
            ans+=grid.at(r1).at(c1);
        else
            ans+=grid.at(r1).at(c1)+grid.at(r2).at(c2);
        int nxt=INFS;
        nxt=max(nxt,get_dp(r1,c1+1,c2+1,grid));
        nxt=max(nxt,get_dp(r1,c1+1,c2,grid));
        nxt=max(nxt,get_dp(r1+1,c1,c2,grid));
        nxt=max(nxt,get_dp(r1+1,c1,c2+1,grid));
        ans+=nxt;
        dp[r1][c1][c2]=ans;
        return ans;
    }
};
