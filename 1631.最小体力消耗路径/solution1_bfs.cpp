//记忆化bfs走完起点到所有点的距离
const int MAXN=100;
int dp[MAXN][MAXN];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
struct pii{
    int x,y,val;
};
class Solution {
    int row,col;
    int INF=0x3f3f3f3f;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        row=heights.size();
        col=heights.at(0).size();
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=0;
        queue<pii> que;
        que.push({0,0,0});
        while (!que.empty())
        {
            auto [x,y,val]=que.front();
            que.pop();
            if (dp[x][y]<val)
                continue;
            for (int i=0;i<4;++i)
            {
                int xx=x+dx[i];
                int yy=y+dy[i];
                if (!(xx>=0 && xx<row && yy>=0 && yy<col))
                    continue;
                int vv=max(val,abs(heights.at(xx).at(yy)-heights.at(x).at(y)));
                if (dp[xx][yy]<=vv)
                    continue;
                que.push({xx,yy,vv});
                dp[xx][yy]=min(dp[xx][yy],vv);
            }
        }
        return dp[row-1][col-1];
    }
};
