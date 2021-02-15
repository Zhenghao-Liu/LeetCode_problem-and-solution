/*
* [tarjan求强连通分量](https://www.bilibili.com/video/BV19J411J7AZ/)
* 连通：无向图中，从任意点i可到达任意点j
  强连通：有向图中，从任意点i可到达任意点j
  弱连通：把有向图当成无向图看时，从任意点i可到达任意点j
* [tarjan求割点和桥](https://www.bilibili.com/video/BV1Q7411e7bM/)
* 割点：无向连通图中，某点和其该点所有连接的边去掉后，图不再连通
  桥：无向连通图中，某边去掉后，图不再连通
* 两个视频都要看，有关联
*/
/*
* x->y是桥，low[y]>dfn[x]
* 环边一定不是桥
* 采用特别的dfs方式，先向下dfs，再处理当前节点
*/
class Solution {
    vector<vector<int>> edge;
    vector<int> dfn;
    vector<int> low;
    vector<vector<int>> ans;
    int time;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        edge=vector<vector<int>>(n);
        dfn=vector<int>(n,0);
        low=vector<int>(n,0);
        ans.clear();
        time=0;
        for (vector<int> &i:connections)
        {
            edge.at(i.at(0)).push_back(i.at(1));
            edge.at(i.at(1)).push_back(i.at(0));
        }
        tarjan(0,-1);
        return ans;
    }
    void tarjan(int cur,int pre)
    {
        ++time;
        dfn.at(cur)=time;
        low.at(cur)=time;
        for (int next:edge.at(cur))
        {
            if (next==pre)
                continue;
            if (dfn.at(next)==0)
            {
                tarjan(next,cur);
                low.at(cur)=min(low.at(cur),low.at(next));
                if (low.at(next)>dfn.at(cur))
                    ans.push_back({cur,next});
            }
            //代表出现了环，该节点cur可以连接到前面已经访问过的节点
            //即是环边，环边一定不是桥
            else
                low.at(cur)=min(low.at(cur),low.at(next));
        }
    }
};
