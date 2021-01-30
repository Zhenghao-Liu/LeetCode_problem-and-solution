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

    bool is_connected(int a,int b) {
        return find_root(a)==find_root(b);
    }
};
struct piiv {
    int u,v,val;
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid.at(0).size();
        if (row==1 && col==1) {
            return grid.at(0).at(0);
        }
        union_find uf(row*col);
        int st=0,ed=row*col-1;
        vector<piiv> vec;
        vec.reserve(2*row*col-row-col);
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                int cur=i*col+j;
                int curVal=grid.at(i).at(j);
                if (i-1>=0) {
                    int nxt=(i-1)*col+j;
                    int nxtVal=grid.at(i-1).at(j);
                    vec.push_back({cur,nxt,max(curVal,nxtVal)});
                }
                if (j-1>=0) {
                    int nxt=i*col+j-1;
                    int nxtVal=grid.at(i).at(j-1);
                    vec.push_back({cur,nxt,max(curVal,nxtVal)});
                }
            }
        }
        sort(vec.begin(),vec.end(),[](const piiv &A,const piiv &B){
            return A.val<B.val;
        });
        for (auto &[u,v,val]:vec) {
            uf.union_vertices(u,v);
            if (uf.is_connected(st,ed)) {
                return val;
            }
        }
        return -1;
    }
};
