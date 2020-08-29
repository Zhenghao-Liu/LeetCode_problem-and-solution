/*
* 题意即删除一条边，使得剩下图是无环无向图
  那么只需用并查集找出成环的最后一条边即可
* 题目说了n个节点n条边
* 且要求是删除二维数组最后出现的边
* 所以应该正序遍历，如果是逆序遍历找出来的是可以删除的第一条边
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int edges_size=edges.size();
        union_find uf(edges_size+1);
        for (vector<int> &i:edges)
            if (!uf.union_vertices(i.at(0),i.at(1)))
                return i;
        return {};
    }
};
