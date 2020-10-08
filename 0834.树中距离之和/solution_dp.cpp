/*
 * 状态方程dp[i]=dp[pre]-back+front-1
 * 一次dfs求得
   1. 以某起点到所有点的距离
   2. 以某起点为dfs顺序的，该节点的：前面路径的节点数以及后面路径节点数
 * 第二次dfs则是状态转移
 */
typedef pair<int,int> pii;
const int MAXN=10000;
int vis[MAXN];
class Solution {
    vector<vector<int>> edges;
    int N;
    vector<int> ans;
    vector<pii> front_back;
public:
    vector<int> sumOfDistancesInTree(int _N, vector<vector<int>>& _edges) {
        if (_N==1)
            return {0};
        N=_N;
        edges=vector<vector<int>>(N);
        for (vector<int> &i:_edges)
        {
            edges.at(i.at(0)).push_back(i.at(1));
            edges.at(i.at(1)).push_back(i.at(0));
        }
        ans=vector<int>(N);
        front_back=vector<pii>(N);
        //任意选择起点
        int start_node=0;
        int start_node_dis=0;
        memset(vis,0,sizeof(vis));
        dfs_front_back_start_node_dist(start_node,start_node_dis,0);
        ans.at(start_node)=start_node_dis;
        memset(vis,0,sizeof(vis));
        dfs_ans(start_node,start_node_dis);
        return ans;
    }
    int dfs_front_back_start_node_dist(int cur,int &start_node_dis,int dis)
    {
        start_node_dis+=dis;
        int back=0;
        vis[cur]=1;
        for (int nxt:edges.at(cur))
            if (vis[nxt]==0)
                back+=dfs_front_back_start_node_dist(nxt,start_node_dis,dis+1);
        front_back.at(cur)={N-1-back,back};
        return back+1;
    }
    void dfs_ans(int cur,int prev_ans)
    {
        vis[cur]=1;
        if (ans.at(cur)==0)
        {
            int front=front_back.at(cur).first;
            int back=front_back.at(cur).second;
            ans.at(cur)=prev_ans-back+front-1;
        }
        for (int nxt:edges.at(cur))
            if (vis[nxt]==0)
                dfs_ans(nxt,ans.at(cur));
    }
};
