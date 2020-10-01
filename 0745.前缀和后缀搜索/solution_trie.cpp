/*
 * 选择正着插入字典树，反着插入另外一课字典树，然后dfs求交集并求最大权重的方法会tle
 * 就考虑如何只靠一棵字典树就能完成要求
 * 插入单词words[i]时，将{所有可能的后缀+分界符+words[i]单词本身}的形式插入字典树
   eg:words[i]=s="apple"，选定分界符是'#'
   即要插入的所有情况是
   apple#apple、pple#apple、ple#apple、le#apple、e#apple、#apple
 * 这样在查找前缀prefix和后缀suffix时，可以组合成单词：{suffix+分界符+preffix}来查找
   eg:prefix:ap，suffix：le，即组合成target=le#ap，这样就可以在字典树中search
 * 注意search不一定是search到完整的单词，因为我们是把整个前缀(单词)存了进去
   且注意在存单词时更新对应的权重val
 */
class Trie {
private:
    //数组初始化只有全为0才能这样写
    Trie* arc[27]={NULL};
    int val=0;
public:
    /** Initialize your data structure here. */
    Trie(){}
    
    /** Inserts a word into the trie. */
    void insert(string &word,int start,int _val) {
        Trie* p=this;
        int size=word.size();
        for (int i=start;i<size;++i)
        {
            int index= word.at(i)=='#' ? 26 : word.at(i)-'a';
            if (p->arc[index]==NULL)
                p->arc[index]=new Trie;
            p=p->arc[index];
            p->val=max(p->val,_val);
        }
    }
    
    int search(string &word) {
        Trie* p=this;
        int size=word.size();
        for (int i=0;i<size;++i)
        {
            int index= word.at(i)=='#' ? 26 : word.at(i)-'a';
            if (p->arc[index]==NULL)
                return -1;
            else
                p=p->arc[index];
        }
        return p->val;
    }
};
class WordFilter {
    Trie trie;
public:
    WordFilter(vector<string>& words) {
        int words_size=words.size();
        string s;
        for (int i=0;i<words_size;++i)
        {
            s=words.at(i)+"#"+words.at(i);
            int words_i_size=words.at(i).size();
            for (int j=0;j<=words_i_size;++j)
                trie.insert(s,j,i);
        }
    }
    
    int f(string prefix, string suffix) {
        string target=suffix+"#"+prefix;
        return trie.search(target);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
