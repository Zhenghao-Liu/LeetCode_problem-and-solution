/*
 * 选危险最大的病毒区域进行隔离，然后病毒扩散，然后重复选择，直到结束
 * 将-1设为已经隔离的区域
 */
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
const int MAXN=50;
int vis[MAXN][MAXN];
typedef pair<int,int> pii;
class Solution {
    int row,column;
public:
    int containVirus(vector<vector<int>>& grid) {
        row=grid.size();
        column=grid.at(0).size();
        int ans=0;
        //first是坐标i*column+j，second是病毒扩散周边的数目
        vector<pii> virus;
        while (true)
        {
            virus.clear();
            get_virus(virus,grid);
            sort(virus.begin(),virus.end(),[](const pii &A,const pii &B){
                return A.second>B.second;
            });
            int virus_size=virus.size();
            bool judge_find=false;
            for (int i=0;i<virus_size;++i)
                if (virus.at(i).second>0)
                {
                    int x=virus.at(i).first/column;
                    int y=virus.at(i).first%column;
                    get_firewall(ans,grid,x,y);
                    judge_find=true;
                    break;
                }
            if (!judge_find)
                break;
            get_infect(grid);
        }
        return ans;
    }
    void get_virus(vector<pii> &virus,vector<vector<int>> &grid)
    {
        memset(vis,0,sizeof(vis));
        int area_num=0;
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (vis[i][j]==0 && grid.at(i).at(j)==1)
                {
                    ++area_num;
                    int coordinates=i*column+j;
                    int expand=expand_dfs(grid,i,j,area_num);
                    virus.push_back({coordinates,expand});
                }
    }
    int expand_dfs(vector<vector<int>> &grid,int x,int y,int area_num)
    {
        if (!(x>=0 && x<row && y>=0 && y<column) || vis[x][y]==1 || vis[x][y]==area_num || grid.at(x).at(y)==-1)
            return 0;
        if (grid.at(x).at(y)==0)
        {
            vis[x][y]=area_num;
            return 1;
        }
        vis[x][y]=1;
        int res=0;
        for (int i=0;i<4;++i)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            res+=expand_dfs(grid,xx,yy,area_num);
        }
        return res;
    }
    void get_firewall(int &ans,vector<vector<int>> &grid,int x,int y)
    {
        memset(vis,0,sizeof(vis));
        ans+=firewall_dfs(grid,x,y);
    }
    int firewall_dfs(vector<vector<int>> &grid,int x,int y)
    {
        if (!(x>=0 && x<row && y>=0 && y<column) || grid.at(x).at(y)==-1)
            return 0;
        if (vis[x][y]==1 && grid.at(x).at(y)==1)
            return 0;
        if (grid.at(x).at(y)==0)
            return 1;
        vis[x][y]=1;
        grid.at(x).at(y)=-1;
        int res=0;
        for (int i=0;i<4;++i)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            res+=firewall_dfs(grid,xx,yy);
        }
        return res;
    }
    void get_infect(vector<vector<int>> &grid)
    {
        memset(vis,0,sizeof(vis));
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (vis[i][j]==0 && grid.at(i).at(j)==1)
                    infect_dfs(grid,i,j);
    }
    void infect_dfs(vector<vector<int>> &grid,int x,int y)
    {
        if (!(x>=0 && x<row && y>=0 && y<column) || vis[x][y]==1 || grid.at(x).at(y)==-1)
            return;
        vis[x][y]=1;
        if (grid.at(x).at(y)==0)
        {
            grid.at(x).at(y)=1;
            return;
        }
        for (int i=0;i<4;++i)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            infect_dfs(grid,xx,yy);
        }
    }
};
