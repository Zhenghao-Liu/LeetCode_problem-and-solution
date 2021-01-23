// 看下有多少多余的边，以及有多少个集合，能否用多余的边连接起剩下的集合即可
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        union_find uf(n);
        int cnt=0;
        for (vector<int> &i:connections) {
            int a=i.at(0);
            int b=i.at(1);
            if (!uf.union_vertices(a,b)) {
                cnt++;
            }
        }
        int all=0;
        for (int i=0;i<n;i++) {
            if (uf.find_root(i)==i) {
                all++;
            }
        }
        all--;
        return cnt>=all ? all : -1; 
    }
};
