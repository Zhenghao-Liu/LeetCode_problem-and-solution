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
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int sz=strs.size();
        union_find uf(sz);
        int len=strs.at(0).size();
        for (int i=0;i<sz;i++) {
            for (int j=i+1;j<sz;j++) {
                // 剪枝
                if (uf.is_connected(i,j)) {
                    continue;
                }
                // 保证了是彼此的字母异位词，所以只需要确保不同的位置要么为0要么为2即可
                int cnt=0;
                for (int k=0;k<len;k++) {
                    if (strs.at(i).at(k)!=strs.at(j).at(k)) {
                        cnt++;
                    }
                    if (cnt>2) {
                        break;
                    }
                }
                if (cnt==2 || cnt==0) {
                    uf.union_vertices(i,j);
                }
            }
        }
        int ans=0;
        for (int i=0;i<sz;i++) {
            if (uf.find_root(i)==i) {
                ans++;
            }
        }
        return ans;
    }
};
