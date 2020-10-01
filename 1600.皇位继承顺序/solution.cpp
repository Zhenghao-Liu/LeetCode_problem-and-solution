//仔细理解，其实皇位顺序，就是建树后，前序遍历的顺序
class ThroneInheritance {
    string kn;
    unordered_map<string,vector<string>> son;
    unordered_set<string> dea;
    vector<string> ans;
public:
    ThroneInheritance(string kingName) {
        kn=kingName;
    }
    
    void birth(string parentName, string childName) {
        son[parentName].push_back(childName);
    }
    
    void death(string name) {
        dea.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        ans.clear();
        dfs(kn);
        return ans;
    }
    void dfs(string &s)
    {
        if (dea.find(s)==dea.end())
            ans.push_back(s);
        for (string &i:son[s])
            dfs(i);
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
