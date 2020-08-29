/*
* 本题与上一题区别在于变成了有向图
* 按照树的有向图的话，应该每个节点入度最大为1（根节点入度为0）
* 因此我们先找出入度为2的节点，找到该节点设为repeat，表明必定要删除与之相邻的一条边
* 所以我们先并查集处理与入度为2的节点无关的边
* 再单独处理与入度为2的节点有关的边
*/
class union_find
{
private:
    vector<int> parent;
public:
    union_find(){}

    union_find(int n)
    {
        parent=vector<int>(n);
        init(n);
    }

    void init(int n)
    {
        for (int i=0;i<n;++i)
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
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int edges_size=edges.size();
        int repeat=0;
        vector<int> count(edges_size+1,0);
        for (vector<int> &i:edges)
        {
            ++count.at(i.at(1));
            if (count.at(i.at(1))>=2)
            {
                repeat=i.at(1);
                break;
            }
        }
        union_find uf(edges_size+1);
        for (vector<int> &i:edges)
        {
            if (i.at(1)==repeat)
                continue;
            if (!uf.union_vertices(i.at(0),i.at(1)))
                return i;
        }
        for (vector<int> &i:edges)
        {
            if (i.at(1)!=repeat)
                continue;
            if (!uf.union_vertices(i.at(0),i.at(1)))
                return i;
        }
        return {};
    }
};
