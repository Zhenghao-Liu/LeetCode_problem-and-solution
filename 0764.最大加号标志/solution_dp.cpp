//缓存上下左右四个方向有多少个1
const int MAXN=500;
int graph[MAXN][MAXN];
int dp_left[MAXN][MAXN];//->
int dp_right[MAXN][MAXN];//<-
int dp_up[MAXN][MAXN];//↓
int dp_down[MAXN][MAXN];//↑
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        for (int i=0;i<N;++i)
            for (int j=0;j<N;++j)
                graph[i][j]=1;
        for (vector<int> &vec:mines)
        {
            int i=vec.at(0),j=vec.at(1);
            graph[i][j]=0;
        }
        for (int i=0;i<N;++i)
        {
            dp_left[i][0]=0;
            for (int j=1;j<N;++j)
                if (graph[i][j-1]==1)
                    dp_left[i][j]=dp_left[i][j-1]+1;
                else
                    dp_left[i][j]=0;
            dp_right[i][N-1]=0;
            for (int j=N-2;j>=0;--j)
                if (graph[i][j+1]==1)
                    dp_right[i][j]=dp_right[i][j+1]+1;
                else
                    dp_right[i][j]=0;
        }
        for (int j=0;j<N;++j)
        {
            dp_up[0][j]=0;
            for (int i=1;i<N;++i)
                if (graph[i-1][j]==1)
                    dp_up[i][j]=dp_up[i-1][j]+1;
                else
                    dp_up[i][j]=0;
            dp_down[N-1][j]=0;
            for (int i=N-2;i>=0;--i)
                if (graph[i+1][j]==1)
                    dp_down[i][j]=dp_down[i+1][j]+1;
                else
                    dp_down[i][j]=0;
        }
        int ans=0;
        for (int i=0;i<N;++i)
            for (int j=0;j<N;++j)
                if (graph[i][j]==1)
                {
                    int cur=min(min(dp_left[i][j],dp_right[i][j]),min(dp_up[i][j],dp_down[i][j]));
                    ans=max(ans,cur+1);
                }
        return ans;
    }
};
