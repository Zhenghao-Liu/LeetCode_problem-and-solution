/*
 * 把矩阵中每个位置当成图的每一个点
 * 把矩阵中每个位置上下左右可以走的路径，当成点的边
 * 把邻格子之间高度差绝对值，当成是该边的权值
 * 那么就可以构建一个图，且最终答案是高度差绝对值的最大值
   可以按权值按升序排序，不断处理
 * 判断是否连通，就用到并查集
 * 只要左上角与右下角连通了，那么高大差绝对值的最大值，
   因为按升序排序了，所以就是当前边的权值
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

    bool judge_connected(int a,int b)
    {
        return find_root(a)==find_root(b);
    }
};
struct piiv
{
    int x,y,val;
};
class Solution {
    int row,col;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        row=heights.size();
        col=heights.at(0).size();
        int all=row*col;
        vector<piiv> edge;
        int edge_size=(row-1)*col+(col-1)*row;
        edge.reserve(edge_size);
        for (int i=0;i<row;++i)
            for (int j=0;j<col;++j)
            {
                int x_idx=get_idx(i,j);
                //左
                if (j-1>=0)
                {
                    int val=abs(heights.at(i).at(j)-heights.at(i).at(j-1));
                    int y_idx=get_idx(i,j-1);
                    edge.push_back({x_idx,y_idx,val});
                }
                //上
                if (i-1>=0)
                {
                    int val=abs(heights.at(i).at(j)-heights.at(i-1).at(j));
                    int y_idx=get_idx(i-1,j);
                    edge.push_back({x_idx,y_idx,val});
                }
            }
        sort(edge.begin(),edge.end(),[](const piiv &A,const piiv &B){
            return A.val<B.val;
        });
        union_find uf(all);
        int start_idx=0;
        int end_idx=get_idx(row-1,col-1);
        for (int i=0;i<edge_size;++i)
        {
            auto [x_idx,y_idx,val]=edge.at(i);
            uf.union_vertices(x_idx,y_idx);
            if (uf.judge_connected(start_idx,end_idx))
                return val;
        }
        return 0;
    }
    int get_idx(int x,int y)
    {
        return x*col+y;
    }
};
