/*
 * 因为n<=15，所以就往状压dp去想
   但是本题之间状态的转移是转移不了的，但是复杂度的思路是对的2^15
   所以想法：二进制压缩状态，枚举所有情况
 * 本题的树，可以看成是无向无环联通图（二者等价）
 * 枚举状态，要首先判断是否无效
   1. 该状态只有1个节点，因为题目要求的d最小是1，即距离为1，所以可以剪枝
   2. 该状态下不是一个子树，即不是一个联通图，那怎么判断是否是联通图？
      通过bfs或dfs判断能到达的节点的个数，是否和集合内元素个数(二进制下1的个数)相同即可
 * 判断了该状态是有效后，如何求最大距离？
   最大距离，其实就是无向无环联通图的最大直径，lc有原题：树的直径、二叉树的直径啊都是一样的
   1. 任选一节点作为开始节点a，去bfs找到离该节点最远的节点b
   2. 从节点b开始，去bfs找到离b最远的节点的c
   3. b与c之间的距离就是该状态下最大距离，即该(子)图的最大直接
 * 注意本题是序号1开始的，所以空间要多开一位
 * 总体复杂度在O(2^n*(n+n))
 */
const int MAXN=15+1;
int vis[MAXN];
class Solution {
    vector<vector<int>> edges;
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& _edges) {
        edges=vector<vector<int>>(n+1);
        for (vector<int> &i:_edges)
        {
            edges.at(i.at(0)).push_back(i.at(1));
            edges.at(i.at(1)).push_back(i.at(0));
        }
        int ALL=(1<<n)-1;
        vector<int> ans(n-1,0);
        for (int i=1;i<=ALL;++i)
        {
            bitset<MAXN> bs(i);
            int cnt_node=bs.count();
            if (cnt_node<=1)
                continue;
            int start_node;
            for (int j=0;j<n;++j)
                if (bs[j]==1)
                {
                    start_node=j+1;
                    break;
                }
            int start_link_cnt=0;
            int diameter=-1;
            bfs(start_node,bs,start_link_cnt,diameter);
            if (start_link_cnt!=cnt_node)
                continue;
            start_link_cnt=0;
            diameter=-1;
            bfs(start_node,bs,start_link_cnt,diameter);
            ++ans.at(diameter-1);
        }
        return ans;
    }
    void bfs(int &start_node,bitset<MAXN> & bs,int &start_link_cnt,int &diameter)
    {
        memset(vis,0,sizeof(vis));
        queue<int> que;
        que.push(start_node);
        vis[start_node]=1;
        int last_node=start_node;
        while (!que.empty())
        {
            int size=que.size();
            start_link_cnt+=size;
            ++diameter;
            for (int i=0;i<size;++i)
            {
                int cur=que.front();
                que.pop();
                last_node=cur;
                for (int nxt:edges.at(cur))
                    if (vis[nxt]==0 && bs[nxt-1]==1)
                    {
                        vis[nxt]=1;
                        que.push(nxt);
                    }
            }
        }
        start_node=last_node;
    }
};
