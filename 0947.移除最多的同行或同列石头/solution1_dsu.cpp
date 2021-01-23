/*
 * 并查集：将同行同列的都放在一个集合，因为是最大移除的数量，所以一定有方法可以移除到每个集合只有一个石子
 * 降低复杂度，因为是1e4数据量，所以可以通过y+1e4来区分x
 */
const int MAXN=1e4;
class union_find
{
private:
    vector<int> parent;
    vector<int> rank;
public:
    union_find()
    {
        parent.clear();
        rank.clear();
    }
    
    union_find(int n)
    {
        parent=vector<int>(n);
        rank=vector<int>(n,0);
        init(n);
    }

    void init(int n)
    {
        for (int i=0;i<n;++i)
        {
            parent.at(i)=i;
            rank.at(i)=0;
        }
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
        if (rank.at(a_root)<rank.at(b_root))
            parent.at(a_root)=b_root;
        else
        {
            parent.at(b_root)=a_root;
            if (rank.at(a_root)==rank.at(b_root))
                ++rank.at(a_root);
        }
        return true;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        union_find uf(2*MAXN+1);
        for (vector<int> &i:stones) {
            int x=i.at(0);
            int y=i.at(1)+MAXN;
            uf.union_vertices(x,y);
        }
        unordered_set<int> ust;
        for (vector<int> &i:stones) {
            int x=uf.find_root(i.at(0));
            ust.insert(x);
            int y=uf.find_root(i.at(1)+MAXN);
            ust.insert(y);
        }
        return stones.size()-ust.size();
    }
};
