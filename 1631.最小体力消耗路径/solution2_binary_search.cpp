//二分答案，之后用bfs方式判断能否通过该答案走到右下角
const int MAXN=100;
int vis[MAXN][MAXN];
typedef pair<int,int> pii;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights.at(0).size();
        if (row==1 && col==1)
            return 0;
        //1 <= heights[i][j] <= 1e6
        int l=0,r=999999;
        while (l<r)
        {
            int mid=l+(r-l)/2;
            bool flag=false;
            memset(vis,0,sizeof(vis));
            vis[0][0]=1;
            queue<pii> que;
            que.push({0,0});
            while (!que.empty())
            {
                auto [x,y]=que.front();
                que.pop();
                int cur=heights.at(x).at(y);
                for (int i=0;i<4;++i)
                {
                    int xx=x+dx[i];
                    int yy=y+dy[i];
                    if (!(xx>=0 && xx<row && yy>=0 && yy<col))
                        continue;
                    if (vis[xx][yy]==1)
                        continue;
                    int dis=abs(heights.at(xx).at(yy)-cur);
                    if (dis<=mid)
                    {
                        vis[xx][yy]=1;
                        que.push({xx,yy});
                        if (xx==row-1 && yy==col-1)
                        {
                            flag=true;
                            break;
                        }
                    }
                }
            }
            if (flag)
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
