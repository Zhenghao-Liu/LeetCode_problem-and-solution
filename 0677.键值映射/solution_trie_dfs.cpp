class Trie {
private:
    bool is_leaf=false;
    //数组初始化只有全为0才能这样写
    Trie* arc[26]={NULL};
    int _val=0;
public:
    /** Initialize your data structure here. */
    Trie() {
        memset(arc,0,sizeof(arc));
        is_leaf=false;
        _val=0;
    }
    
    /** Inserts a word into the trie. */
    void insert(string &word,int val) {
        Trie* p=this;
        for (char &i:word)
        {
            if (p->arc[i-'a']==NULL)
                p->arc[i-'a']=new Trie;
            p=p->arc[i-'a'];
        }
        p->is_leaf=true;
        p->_val=val;
    }

    int get_sum(Trie *p,string & prefix)
    {
        for (char &i:prefix)
            if (p->arc[i-'a']==NULL)
                return 0;
            else
                p=p->arc[i-'a'];
        return dfs(p);
    }
    int dfs(Trie *p)
    {
        int ans=0;
        if (p->is_leaf)
            ans+=p->_val;
        for (int i=0;i<26;++i)
            if (p->arc[i]!=NULL)
                ans+=dfs(p->arc[i]);
        return ans;
    }

};
class MapSum {
    Trie dict;
public:
    /** Initialize your data structure here. */
    MapSum() {
        dict=Trie();
    }
    
    void insert(string key, int val) {
        dict.insert(key,val);
    }
    
    int sum(string prefix) {
        return dict.get_sum(&dict,prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
