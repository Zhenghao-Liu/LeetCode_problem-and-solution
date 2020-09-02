/*
* 首先需要[200.岛屿数量]来求得grid中岛屿数量
  1. 若0个岛或多个岛则已经是分离的，ans=0
  2. 若1个岛屿，这种情况下答案只有可能是1或2
* 答案是1很好理解，就是切断中间的1个
* 那么2呢，只需要像实例1那样，找到角落的一个四个点，然后删除对角即可
  eg:[1 1 1 1]
     [1 1 1 1]
     [1 1 1 1]
  只用删除2个点即
     [1 0 1 1]
     [0 1 1 1]
     [1 1 1 1]
* 因此先搜索一次岛屿数量，判断ans=0的情况
  再枚举ans=1的情况，枚举删除任意一个点
  剩下自然就只有ans=2情况
*/
const int MAXN=30;
int use[MAXN][MAXN];
int dir_x[]={-1,1,0,0};
int dir_y[]={0,0,-1,1};
class Solution {
    int row,column;
public:
    int minDays(vector<vector<int>>& grid) {
        row=grid.size();
        column=grid.at(0).size();
        int count=check_island(grid);
        if (count!=1)
            return 0;
        for (vector<int> &i:grid)
            for (int &j:i)
                if (j==1)
                {
                    j=0;
                    count=check_island(grid);
                    if (count!=1)
                        return 1;
                    j=1;
                }
        return 2;
    }
    int check_island(vector<vector<int>>& grid)
    {
        memset(use,0,sizeof(use));
        int count=0;
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (grid.at(i).at(j)==1 && use[i][j]==0)
                {
                    ++count;
                    if (count>1)
                        return count;
                    dfs(grid,i,j);
                }
        return count;
    }
    void dfs(vector<vector<int>>& grid,int x,int y)
    {
        use[x][y]=1;
        for (int k=0;k<4;++k)
        {
            int xx=x+dir_x[k];
            int yy=y+dir_y[k];
            if (xx>=0 && xx<row && yy>=0 && yy<column && grid.at(xx).at(yy)==1 && use[xx][yy]==0)
                dfs(grid,xx,yy);
        }
    }
};
