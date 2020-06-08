class Solution {
    unordered_map<char,char> parent;
public:
    bool equationsPossible(vector<string>& equations) {
        parent.clear();
        int equations_size=equations.size();
        vector<int> unequal;
        vector<int> equeal;
        for (int i=0;i<equations_size;++i)
        {
            if (equations.at(i).at(1)=='=')
                equeal.push_back(i);
            else
                unequal.push_back(i);
            initialise(equations.at(i).at(0));
            initialise(equations.at(i).at(3));
        }
        for (int &i:equeal)
            union_vertices(equations.at(i).at(0),equations.at(i).at(3));
        for (int &i:unequal)
        {
            char a_root=find_root(equations.at(i).at(0));
            char b_root=find_root(equations.at(i).at(3));
            if (a_root==b_root)
                return false;
        }
        return true;
    }
    void initialise(char c)
    {
        if (parent.find(c)==parent.end())
            parent.insert({c,c});
    }
    char find_root(char c)
    {
        if (parent.at(c)!=c)
        {
            char root=find_root(parent.at(c));
            parent.at(c)=root;
            return root;
        }
        return c;
    }
    void union_vertices(char a,char b)
    {
        char a_root=find_root(a);
        char b_root=find_root(b);
        if (a_root==b_root)
            return;
        parent.at(a_root)=b_root;
    }
};
