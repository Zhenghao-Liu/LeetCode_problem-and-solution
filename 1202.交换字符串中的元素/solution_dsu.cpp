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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int size=s.size();
        union_find uf(size);
        for (vector<int> &i:pairs) {
            int a=i.at(0);
            int b=i.at(1);
            uf.union_vertices(a,b);
        }
        unordered_map<int,vector<char>> ump;
        for (int i=0;i<size;i++) {
            int root=uf.find_root(i);
            ump[root].push_back(s.at(i));
        }
        for (auto &i:ump) {
            sort(i.second.rbegin(),i.second.rend());
        }
        for (int i=0;i<size;i++) {
            int root=uf.find_root(i);
            s.at(i)=ump.at(root).back();
            ump.at(root).pop_back();
        }
        return s;
    }
};
