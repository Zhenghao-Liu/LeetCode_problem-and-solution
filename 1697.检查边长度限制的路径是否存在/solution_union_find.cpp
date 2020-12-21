/*
 * 在线算法：以流的形式，先进先出，按一定顺序处理
   离线算法：以包的形式，没有固定顺序
 * 本题是离线算法，所以可以先针对queries[2]进行从大到小排序
 * 并对edge按照edge[2]从小到大排序，加入并查集中
   判断在queries[2]限制下，queries[0]和[1]是否联通即可
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
    
    bool connect(int a,int b)
    {
        return find_root(a)==find_root(b);
    }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        union_find uf(n);
        sort(edgeList.begin(),edgeList.end(),[](const vector<int> &A,const vector<int> &B){
            return A.at(2)<B.at(2);
        });
        int q_size=queries.size();
        int e_size=edgeList.size();
        vector<bool> ans(q_size,false);
        vector<int> idx(q_size);
        for (int i=0;i<q_size;++i)
            idx.at(i)=i;
        sort(idx.begin(),idx.end(),[&queries](const int &A,const int &B){
            return queries.at(A).at(2)<queries.at(B).at(2);
        });
        int have_edge=0;
        int j=0;
        for (int i=0;i<q_size;++i)
        {
            int ii=idx.at(i);
            int f=queries.at(ii).at(0);
            int t=queries.at(ii).at(1);
            int d=queries.at(ii).at(2);
            for (;j<e_size;++j)
            {
                if (have_edge==n-1)
                    break;
                int u=edgeList.at(j).at(0);
                int v=edgeList.at(j).at(1);
                int dis=edgeList.at(j).at(2);
                if (dis>=d)
                    break;
                if (uf.union_vertices(u,v))
                    ++have_edge;
            }
            if (uf.connect(f,t))
                ans.at(ii)=true;
        }
        return ans;
    }
};
