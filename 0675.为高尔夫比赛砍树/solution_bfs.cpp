/*
* 你被要求按照树的高度从低向高砍掉所有的树;且树高度不同
* 所以把树的高度进行排序，然后每次移动即可
* 因为卡常所以use设置成静态数组
*/
const int MAXN=50;
int use[MAXN][MAXN];
int dir_x[4]={-1,1,0,0};
int dir_y[4]={0,0,-1,1};
typedef pair<int,int> pii;
class Solution {
    int start_x,start_y;
    int row,column;
public:
    int cutOffTree(vector<vector<int>>& forest) {
        start_x=start_y=0;
        row=forest.size();
        column=forest.at(0).size();
        vector<pii> target;
        target.reserve(row*column);
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (forest.at(i).at(j)!=0)
                    target.push_back({i,j});
        sort(target.begin(),target.end(),[&forest](const pii& A,const pii &B){
            return forest.at(A.first).at(A.second)<forest.at(B.first).at(B.second);
        });
        int target_size=target.size();
        int ans=0;
        for (int i=0;i<target_size;++i)
        {
            int target_x=target.at(i).first;
            int target_y=target.at(i).second;
            int step=bfs(forest,target_x,target_y);
            if (step==-1)
                return -1;
            ans+=step;
            start_x=target_x;
            start_y=target_y;
        }
        return ans;
    }
    int bfs(vector<vector<int>>& forest,int target_x,int target_y)
    {
        if (target_x==start_x && target_y==start_y)
            return 0;
        memset(use,0,sizeof(use));
        queue<pii> helper;
        helper.push({start_x,start_y});
        use[start_x][start_y]=1;
        int ans=-1;
        while (!helper.empty())
        {
            ++ans;
            int size=helper.size();
            for (int i=0;i<size;++i)
            {
                auto [x,y]=helper.front();
                helper.pop();
                if (x==target_x && y==target_y)
                    return ans;
                for (int k=0;k<4;++k)
                {
                    int xx=x+dir_x[k];
                    int yy=y+dir_y[k];
                    if (!(xx>=0 && xx<row && yy>=0 && yy<column))
                        continue;
                    if (use[xx][yy]!=0 || forest.at(xx).at(yy)==0)
                        continue;
                    helper.push({xx,yy});
                    use[xx][yy]=1;
                }
            }
        }
        return -1;
    }
};
