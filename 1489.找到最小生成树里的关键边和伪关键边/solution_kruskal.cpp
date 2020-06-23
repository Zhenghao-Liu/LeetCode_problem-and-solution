/*
* 关键边：最小生成树中删去某条边，会导致最小生成树的权值和增加
  解法：1. 该边必须出现在mst中
       2. 删除该边，重新构建mst则权值会和会改变
       注：有可能一开始给的图就是mst，即删除边后无法构建mst导致权值和反而变小
           正常情况就是该边是关键边，那么权值和会变大
* 伪关键边：可能会出现在某些最小生成树中但不会出现在所有最小生成树中的边
  解法：1. 可能出现在mst中
       2. 把该边一开始就加入最终生成树中，看最后权值不变则是伪关键边
       3. 且一定不是关键边
* 求最小生成树这里用克鲁斯卡尔，判断有无环用并查集
* 注意最后ans是在_edges的索引所以要提前存好索引以免排序就乱了
*/
class Solution {
    vector<vector<int>> edges;
    vector<int> parent;
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& _edges) {
        edges.clear();
        int _edges_size=_edges.size();
        for (int i=0;i<_edges_size;++i)
        {
            edges.push_back(_edges.at(i));
            edges.at(i).push_back(i);
        }
        parent=vector<int>(n);
        //使用kruskal所以权值要按从小到大排序
        sort(edges.begin(),edges.end(),[](const vector<int> &A,const vector<int> &B){
            return A.at(2)<B.at(2);
        });
        //求mst的最小权值和，因为没有删除的边就一个无意义的数组
        int mst_weight_sum=kruskal(n,{-1,-1,-1});
        //求关键边
        vector<int> key_edge=get_key_edge(n,mst_weight_sum);
        //求伪关键边，且伪关键边中不能有关键边
        unordered_set<int> key_edge_set(key_edge.begin(),key_edge.end());
        vector<int> fake_key_edge=get_fake_key_edge(n,mst_weight_sum,key_edge_set);
        return {key_edge,fake_key_edge};
    }
    void initialise(int n)
    {
        for(int i=0;i<n;++i)
            parent.at(i)=i;
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
    bool union_vertices(int a,int b)
    {
        int a_root=find_root(a);
        int b_root=find_root(b);
        if (a_root==b_root)
            return false;
        parent.at(a_root)=b_root;
        return true;
    }
    int kruskal(int n,vector<int> delete_edge)
    {
        initialise(n);
        int weight_sum=0;
        int cur_size=0;
        for (vector<int> &i:edges)
        {
            if (i==delete_edge)
                continue;
            if (union_vertices(i.at(0),i.at(1)))
            {
                ++cur_size;
                weight_sum+=i.at(2);
                if (cur_size==n-1)
                    return weight_sum;
            }
        }
        return weight_sum;
    }
    vector<int> get_key_edge(int n,const int & mst_weight_sum)
    {
        vector<int> ans;
        for (vector<int> &i:edges)
        {
            int cur_weight_sum=kruskal(n,i);
            if (cur_weight_sum!=mst_weight_sum)
                ans.push_back(i.at(3));
        }
        return ans;
    }
    vector<int> get_fake_key_edge(int n,const int & mst_weight_sum,unordered_set<int> &key_edge_set)
    {
        vector<int> ans;
        for (vector<int> &i:edges)
        {
            if (key_edge_set.find(i.at(3))!=key_edge_set.end())
                continue;
            int cur_weight_sum=add_one_edge_kruskal(n,i);
            if (cur_weight_sum==mst_weight_sum)
                ans.push_back(i.at(3));
        }
        return ans;
    }
    int add_one_edge_kruskal(int n,vector<int> add_edge)
    {
        initialise(n);
        union_vertices(add_edge.at(0),add_edge.at(1));
        int weight_sum=add_edge.at(2);
        int cur_size=1;
        for (vector<int> &i:edges)
        {
            if (i==add_edge)
                continue;
            if (union_vertices(i.at(0),i.at(1)))
            {
                ++cur_size;
                weight_sum+=i.at(2);
                if (cur_size==n-1)
                    return weight_sum;
            }
        }
        return weight_sum;
    }
};
