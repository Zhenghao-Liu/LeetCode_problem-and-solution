/*
 * 确定两点之间是否连通，就想到用并查集
 * 如果枚举两个点之间的gcd，总复杂度是n^2*logn，不符合要求
 * 题目要求是公因数要大于threshold
 * 所以可以枚举因数，从threshold+1开始枚举所有因数的可能
   将其所有倍数与之该因子相连
 */
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
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        union_find uf(n+1);
        for (int i=threshold+1;i<=n;++i)
            for (int j=i+i;j<=n;j+=i)
                uf.union_vertices(i,j);
        int size=queries.size();
        vector<bool> ans(size);
        for (int i=0;i<size;++i)
        {
            int a_root=uf.find_root(queries.at(i).at(0));
            int b_root=uf.find_root(queries.at(i).at(1));
            if (a_root==b_root)
                ans.at(i)=true;
            else
                ans.at(i)=false;
        }
        return ans;
    }
};
