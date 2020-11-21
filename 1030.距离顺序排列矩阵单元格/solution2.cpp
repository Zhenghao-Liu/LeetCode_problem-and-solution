int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
const int MAXR=100;
const int MAXC=100;
int memo[MAXR][MAXC];
typedef pair<int,int> pii;
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        memset(memo,0,sizeof(memo));
        vector<vector<int>> ans;
        ans.reserve(R*C);
        ans.push_back({r0,c0});
        queue<pii> que;
        memo[r0][c0]=1;
        que.push({r0,c0});
        while (!que.empty())
        {
            int size=que.size();
            for (int i=0;i<size;++i)
            {
                auto [x,y]=que.front();
                que.pop();
                for (int j=0;j<4;++j)
                {
                    int xx=x+dx[j];
                    int yy=y+dy[j];
                    if (!(xx>=0 && xx<R && yy>=0 && yy<C))
                        continue;
                    if (memo[xx][yy]==1)
                        continue;
                    memo[xx][yy]=1;
                    que.push({xx,yy});
                    ans.push_back({xx,yy});
                }
            }
        }
        return ans;
    }
};
