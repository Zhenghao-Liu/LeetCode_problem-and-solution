/*
 * 设每个人的所坐的是座位，每两个相邻的座位构成一张沙发
   即要求交换到最后所有情侣坐一张沙发
 * 把每个沙发作为处理单位，将情侣用边联通起来
   这张图每个节点的度为2，图上存在cnt个连通分量
 * 每次将一个沙发上凑成一对情侣之后，在图上的变化是多了一个自循环的连通分量。
 * 最终目标是让图中有 N 个连通分量，每个连通分量代表一对情侣。
 * 交换顺序不影响结果，且每次交换要么增加一个连通分量，要么不增加
   自然每次是贪心的去交换: 往每次交换都会将连通分量的数量增加1的情况去交换
 * 所以最终答案其实就是 ： 沙发个数-开始时共有几个强连通分量
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
    int minSwapsCouples(vector<int>& row) {
        int seat_size=row.size();
        int sofa_size=seat_size/2;
        union_find uf(sofa_size);
        vector<int> pos(seat_size);
        for (int i=0;i<seat_size;++i)
            pos.at(row.at(i))=i/2;
        for (int i=0;i<seat_size;i+=2)
        {
            int sofa_a=pos.at(i),sofa_b=pos.at(i+1);
            uf.union_vertices(sofa_a,sofa_b);
        }
        int cnt=0;
        for (int i=0;i<sofa_size;++i)
            if (uf.find_root(i)==i)
                ++cnt;
        return sofa_size-cnt;
    }
};
