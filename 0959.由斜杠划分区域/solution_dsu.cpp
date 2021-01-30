/*
 * 把一个斜线划分的方格，看成四个分块a b c e
 * 如果是/，则代表ab一组，ce一组
 * 如果是\，则代表ac一组，be一组
 * 还有方块与方块之间的连通，只要选取左上或者右下即可连通
   选取右下，则cd一组，ef一组
 * 最后统计连通块个数即可
        a
    b       c   d
        e
        f
 */
class union_find
{
private:
    vector<int> parent;
    vector<int> rank;
    int cnt;
public:
    union_find()
    {
        parent.clear();
        rank.clear();
        cnt=0;
    }
    
    union_find(int n)
    {
        parent=vector<int>(n);
        rank=vector<int>(n,0);
        init(n);
    }

    void init(int n)
    {
        cnt=n;
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
        cnt--;
        return true;
    }

    int get_cnt() {
        return cnt;
    }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int row=grid.size();
        int col=grid.at(0).size();
        union_find uf(row*col*4);
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                int idx=(i*col+j)*4;
                char cur=grid.at(i).at(j);
                if (cur=='/') {
                    uf.union_vertices(idx,idx+1);
                    uf.union_vertices(idx+2,idx+3);
                } else if (cur=='\\') {
                    uf.union_vertices(idx,idx+2);
                    uf.union_vertices(idx+1,idx+3);
                } else {
                    uf.union_vertices(idx,idx+1);
                    uf.union_vertices(idx+1,idx+2);
                    uf.union_vertices(idx+2,idx+3);
                }
                if (j+1<col) {
                    int nxt=(i*col+j+1)*4;
                    uf.union_vertices(idx+2,nxt+1);
                }
                if (i+1<row) {
                    int nxt=((i+1)*col+j)*4;
                    uf.union_vertices(idx+3,nxt);
                }
            }
        }
        return uf.get_cnt();
    }
};
