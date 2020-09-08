/*
* 将类型1当做大集合A，类型2当做大集合B，类型3当做集合AB
  即A+B+AB=edges.size()
* 显然类型3是最优的，所以生成树先放入类型3的边
  但注意可能有出现环所以单独cnt_AB记录生成树中类型3的边
  存入parent_AB中表示只存类型3的并查集集合
* 之后分别讨论alice和bob的生成树
  这个生成树都是在parent_AB的基础上延伸
  注意可能做不到连通所有点即返回-1的情况
* 类型1的大集合A，总共有A条边，即edges[i][0]=1的数量
  其中alice的生成树中共有n-1条边，
  且生成树中包括类型3的边cnt_AB条，
  即生成树剩下都来自集合A中，设x条
  即x+cnt_AB=n-1
* 类型2的大集合B，总共有B条边，即edges[i][0]=2的数量
  其中bob的生成树中共有n-1条边，
  且生成树中包括类型3的边cnt_AB条，
  即生成树剩下都来自集合B中，设y条
  即y+cnt_AB=n-1
* 因此可得x+y=(2n-2)-2*cnt_AB
* 即构成生成树的总边其实是x+y+cnt_AB
* 即可以删除的边是edges.size()减去生成树的边
  即edges.size()-(x+y+cnt_AB)=edges.size()-(2n-2-cnt_AB)
*/
typedef pair<int,int> pii;
class Solution {
    vector<int> parent;
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        init(n+1);
        vector<pii> edges_A,edges_B;
        int cnt_AB=0;
        for (vector<int> &i:edges)
        {
            int type=i.at(0);
            int u=i.at(1),v=i.at(2);
            if (type==3)
            {
                if (union_v(u,v))
                    ++cnt_AB;
            }
            else if (type==1)
                edges_A.push_back({u,v});
            else
                edges_B.push_back({u,v});
        }
        vector<int> parent_AB=parent;
        int cnt_A=Kruskal_rest(edges_A,cnt_AB,n);
        if (cnt_A==-1)
            return -1;
        copy(parent_AB.begin(),parent_AB.end(),parent.begin());
        int cnt_B=Kruskal_rest(edges_B,cnt_AB,n);
        if (cnt_B==-1)
            return -1;
        return edges.size()-(2*n-2-cnt_AB);
    }
    void init(int n)
    {
        parent.clear();
        for(int i=0;i<n;++i)
            parent.push_back(i);
    }
    int find_root(int i)
    {
        if (parent.at(i)!=i)
        {
            int root=find_root(parent.at(i));
            parent.at(i)=root;
            return root;
        }
        return i;
    }
    bool union_v(int a,int b)
    {
        int a_root=find_root(a);
        int b_root=find_root(b);
        if (a_root==b_root)
            return false;
        parent.at(a_root)=b_root;
        return true;
    }
    int Kruskal_rest(vector<pii> &edges,int cnt_AB,int n)
    {
        int cnt=cnt_AB;
        for (pii &i:edges)
        {
            int u=i.first,v=i.second;
            if (union_v(u,v))
                ++cnt;
            if (cnt==n-1)
                break;
        }
        return cnt==n-1 ? cnt : -1;
    }
};
