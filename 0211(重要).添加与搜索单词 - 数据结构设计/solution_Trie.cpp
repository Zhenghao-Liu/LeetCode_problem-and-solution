class WordDictionary {
private:
    bool is_leaf=false;
    //数组初始化只有全为0才能这样写
    WordDictionary* arc[26]={NULL};
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary* p=this;
        for (char &i:word)
        {
            if (p->arc[i-'a']==NULL)
                p->arc[i-'a']=new WordDictionary;
            p=p->arc[i-'a'];
        }
        p->is_leaf=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        WordDictionary* p=this;
        int word_size=word.size(),i;
        for (i=0;i<word_size;++i)
        {
            if (word.at(i)=='.')
                break;
            if (p->arc[word.at(i)-'a']==NULL)
                return false;
            else
                p=p->arc[word.at(i)-'a'];
        }
        if (i<word_size)
        {
            vector<char> helper_replace;
            for (int j=0;j<26;++j)
                if (p->arc[j]!=NULL)
                    helper_replace.push_back('a'+j);
            if (!helper_replace.empty())
            {
                bool judge=false;
                for (char &j:helper_replace)
                    if (!judge)
                        judge=this->search(string(word.begin(),word.begin()+i)+j+string(word.begin()+i+1,word.end()));
                    else
                        return true;
                return judge;
            }
            else
                return false;
        }
        return p->is_leaf;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
