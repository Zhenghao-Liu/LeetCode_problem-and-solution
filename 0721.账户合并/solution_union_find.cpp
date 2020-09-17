//将相同mail的并查集合在一个集合，之后通过反向映射获取用户name
class Solution {
    vector<int> parent;
    unordered_map<string,int> mail_index;
    vector<string> index_name;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        parent.clear();
        mail_index.clear();
        index_name.clear();
        int index=-1;
        for (vector<string> &i:accounts)
        {
            int size=i.size();
            for (int j=1;j<size;++j)
                if (mail_index.find(i.at(j))==mail_index.end())
                {
                    ++index;
                    parent.push_back(index);
                    mail_index[i.at(j)]=index;
                    index_name.push_back(i.at(0));
                }
        }
        for (vector<string> &i:accounts)
        {
            int size=i.size();
            for (int j=2;j<size;++j)
                union_vertices(mail_index.at(i.at(1)),mail_index.at(i.at(j)));
        }
        unordered_map<int,set<string>> ret;
        for (auto &[mail,id]:mail_index)
        {
            int root_id=find_root(id);
            ret[root_id].insert(mail);
        }
        vector<vector<string>> ans;
        ans.reserve(ret.size());
        vector<string> vec;
        for (auto &i:ret)
        {
            vec.clear();
            int root_id=i.first;
            string name=index_name.at(root_id);
            vec.push_back(name);
            vec.insert(vec.end(),i.second.begin(),i.second.end());
            ans.push_back(vec);
        }
        return ans;
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

    void union_vertices(int a,int b)
    {
        int a_root=find_root(a);
        int b_root=find_root(b);
        if (a_root==b_root)
            return;
        parent.at(a_root)=b_root;
        return;
    }
};
