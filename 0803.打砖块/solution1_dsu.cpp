/*
 * 普通并查集只能合并，不能拆分
 * 所以需要转化成插砖块，且要逆序的插入hits的方块
 * 因为要统计个数，所以要一个cnt统计个数的数组
 * 可以将第一行即稳定不掉落的数组放在一个集合里面
   但有个问题是怎么永远都能保证找到一个稳定不掉落的集合呢？
   为了方便，额外加一个虚拟节点topRoot，将它放入该集合中，就是用来找不会掉落的这个集合
 * 注意有可能hits的地方本来就不是方块，所以要刚开始不能直接置0，
   可以置一个特殊值-1代表这个地方原来有砖块，但是被hits了，后面会插入
 * 逆序插入hits方块：
   找插入前稳定的集合包含多少个元素，再看插入后稳定的集合的包含多少个元素
   二者相减，再减去hits当前位置即减1，即是除hits当前外，新增进稳定集合的元素个数
   也就是掉落的砖块数
 */
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
class union_find
{
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> cnt;
public:

    union_find(int n=0)
    {
        parent=vector<int>(n);
        rank=vector<int>(n,0);
        cnt=vector<int>(n,1);
        init(n);
    }

    void init(int n)
    {
        for (int i=0;i<n;++i)
        {
            parent.at(i)=i;
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
        {
            parent.at(a_root)=b_root;
            cnt.at(b_root)+=cnt.at(a_root);
        } 
        else
        {
            parent.at(b_root)=a_root;
            cnt.at(a_root)+=cnt.at(b_root);
            if (rank.at(a_root)==rank.at(b_root))
                ++rank.at(a_root);
        }
        return true;
    }

    int size(int a) {
        return cnt.at(find_root(a));
    }
};
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int row=grid.size();
        int col=grid.at(0).size();
        int topRoot=row*col;
        union_find uf(topRoot+1);
        for (vector<int> &i:hits) {
            int x=i.at(0);
            int y=i.at(1);
            if (grid.at(x).at(y)==1) {
                grid.at(x).at(y)=-1;
            }
        }
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                if (grid.at(i).at(j)==1) {
                    int cur=i*col+j;
                    if (i==0) {
                        uf.union_vertices(cur,topRoot);
                    } else {
                        if (i-1>=0 && grid.at(i-1).at(j)==1) {
                            uf.union_vertices(cur,(i-1)*col+j);
                        }
                        if (j-1>=0 && grid.at(i).at(j-1)==1) {
                            uf.union_vertices(cur,i*col+(j-1));
                        }
                    }
                }
            }
        }
        int hits_size=hits.size();
        vector<int> ans(hits_size);
        for (int i=hits_size-1;i>=0;i--) {
            int x=hits.at(i).at(0);
            int y=hits.at(i).at(1);
            if (grid.at(x).at(y)==0) {
                continue;
            }
            int cur=x*col+y;
            grid.at(x).at(y)=1;
            int prevCnt=uf.size(topRoot);
            if (x==0) {
                uf.union_vertices(cur,topRoot);
            }
            for (int j=0;j<4;j++) {
                int xx=x+dx[j];
                int yy=y+dy[j];
                if (!(xx>=0 && xx<row && yy>=0 && yy<col)) {
                    continue;
                }
                if (grid.at(xx).at(yy)!=1) {
                    continue;
                }
                int nxt=xx*col+yy;
                uf.union_vertices(cur,nxt);
            }
            int curCnt=uf.size(topRoot);
            ans.at(i)=max(curCnt-1-prevCnt,0);
        }
        return ans;
    }
};
