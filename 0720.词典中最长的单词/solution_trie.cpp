//将单词放入字典树中，然后从根节点向下dfs
class Trie {
private:
    bool is_leaf=false;
    //数组初始化只有全为0才能这样写
    Trie* arc[26]={NULL};
public:
    /** Initialize your data structure here. */
    Trie() {
        is_leaf=false;
        memset(arc,0,sizeof(arc));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* p=this;
        for (char &i:word)
        {
            if (p->arc[i-'a']==NULL)
                p->arc[i-'a']=new Trie;
            p=p->arc[i-'a'];
        }
        p->is_leaf=true;
    }
    
    void dfs(Trie *p,string &s,string &ans)
    {
        if ((int)s.size()>(int)ans.size())
            ans=s;
        if (p==NULL)
            return;
        for (int i=0;i<26;++i)
            if (p->arc[i]!=NULL && p->arc[i]->is_leaf)
            {
                s+=char('a'+i);
                dfs(p->arc[i],s,ans);
                s.pop_back();
            }
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (string &i:words)
            trie.insert(i);
        string ans,s;
        trie.dfs(&trie,s,ans);
        return ans;
    }
};
