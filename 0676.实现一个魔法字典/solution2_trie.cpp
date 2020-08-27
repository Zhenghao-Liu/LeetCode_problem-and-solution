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
    void insert(string &word) {
        Trie* p=this;
        for (char &i:word)
        {
            if (p->arc[i-'a']==NULL)
                p->arc[i-'a']=new Trie;
            p=p->arc[i-'a'];
        }
        p->is_leaf=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(Trie *p,string &word,int index,bool is_modify)
    {
        if (p==NULL)
            return false;
        if (index==(int)word.size())
            return is_modify && p->is_leaf;
        for (int i=0;i<26;++i)
            if (p->arc[i]!=NULL)
            {
                int c=word.at(index)-'a';
                if (i==c)
                {
                    if (search(p->arc[i],word,index+1,is_modify))
                        return true;
                }
                else if (!is_modify && search(p->arc[i],word,index+1,true))
                    return true;
            }
        return false;
    }
    
};
class MagicDictionary {
    Trie dict;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        dict=Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        dict=Trie();
        for (string &i:dictionary)
            dict.insert(i);
    }
    
    bool search(string searchWord) {
        return dict.search(&dict,searchWord,0,false);
    }
};
