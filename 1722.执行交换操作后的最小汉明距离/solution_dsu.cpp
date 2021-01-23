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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int size=source.size();
        union_find uf(size);
        for (vector<int> &i:allowedSwaps) {
            int a=i.at(0),b=i.at(1);
            uf.union_vertices(a,b);
        }
        vector<vector<int>> s(size);
        vector<vector<int>> t(size);
        unordered_set<int> ust;
        for (int i=0;i<size;i++) {
            int root=uf.find_root(i);
            if (root==i) {
                ust.insert(root);
            }
            s.at(root).push_back(source.at(i));
            t.at(root).push_back(target.at(i));
        }
        int ans=0;
        for (int i:ust) {
            vector<int> &a=s.at(i);
            vector<int> &b=t.at(i);
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            int p1=0,p2=0;
            int siz=a.size();
            int same=0;
            while (p1<siz && p2<siz) {
                if (a.at(p1)==b.at(p2)) {
                    p1++;
                    p2++;
                    same++;
                } else if (a.at(p1)<b.at(p2)) {
                    p1++;
                } else {
                    p2++;
                }
            }
            ans+=siz-same;
        }
        return ans;
    }
};
