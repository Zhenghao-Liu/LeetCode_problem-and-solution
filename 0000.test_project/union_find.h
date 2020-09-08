#ifndef UNION_FIND
#define UNION_FIND

#include <vector>
using namespace std;

class union_find
{
private:
    vector<int> parent;
public:
    union_find()
    {
        parent.clear();
    }
    
    union_find(int n)
    {
        parent=vector<int>(n);
        init(n);
    }

    void init(int n)
    {
        for (int i=0;i<n;++i)
            parent.at(i)=i;
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
        parent.at(a_root)=b_root;
        return true;
    }
};

#endif