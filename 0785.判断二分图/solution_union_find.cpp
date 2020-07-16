//思想和bfs有点像，既然与该点相连的所有节点颜色都一样，那么这些相连的节点应该同属一个集合，即并查集中的父节点相同，倘若出现了该节点和与该节点相连的所有节点的集合出现了同祖先的情况，则false
class Solution {
    vector<int> parent;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size=graph.size();
        initialise(size);
        for (int i=0;i<size;++i)
        {
            int cur_root=find_root(i);
            if (graph.at(i).empty())
                continue;
            int sign=graph.at(i).at(0);
            for (int j:graph.at(i))
                union_vertices(sign,j);
            if (cur_root==find_root(sign))
                return false;
        }
        return true;
    }
    void initialise(int size)
    {
        parent.clear();
        parent.reserve(size);
        for (int i=0;i<size;++i)
            parent.push_back(i);
    }
    int find_root(int cur)
    {
        if (parent.at(cur)==cur)
            return cur;
        int root=find_root(parent.at(cur));
        parent.at(cur)=root;
        return root;
    }
    void union_vertices(int a,int b)
    {
        int a_root=find_root(a);
        int b_root=find_root(b);
        if (a_root==b_root)
            return;
        parent.at(a_root)=b_root;
        return;
    }
};
