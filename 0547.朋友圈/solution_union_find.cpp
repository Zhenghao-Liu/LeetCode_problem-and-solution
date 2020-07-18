class Solution {
    vector<int> parent;
public:
    int findCircleNum(vector<vector<int>>& M) {
        int size=M.size();
        initialise(size);
        //这里是对称矩阵所以第二个可以优化成for(int j=0;j<i;++j)
        for (int i=0;i<size;++i)
            for (int j=0;j<size;++j)
                if (i!=j && M.at(i).at(j)==1)
                    union_vertices(i,j);
        for (int i=0;i<size;++i)
            find_root(i);
        sort(parent.begin(),parent.end());
        return unique(parent.begin(),parent.end())-parent.begin();
    }
    void initialise(int size)
    {
        parent.clear();
        parent.reserve(size);
        for (int i=0;i<size;++i)
            parent.push_back(i);
    }
    int find_root(int i)
    {
        if (parent.at(i)==i)
            return i;
        int root=find_root(parent.at(i));
        parent.at(i)=root;
        return root;
    }
    void union_vertices(int i,int j)
    {
        int i_root=find_root(i);
        int j_root=find_root(j);
        if (i_root==j_root)
            return;
        parent.at(i_root)=j_root;
        return;
    }
};
