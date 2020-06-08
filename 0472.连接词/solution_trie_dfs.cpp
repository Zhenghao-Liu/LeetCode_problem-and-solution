/*
* 建立字典树
* 因为要求是完全由给定单词构成的，所以倘若遍历到是一个单词，那就从该处，在trie的头重新dfs一次
*/
class Trie {
private:
    bool is_leaf=false;
    //数组初始化只有全为0才能这样写
    Trie* arc[26]={NULL};
public:
    /** Initialize your data structure here. */
    Trie() {
        
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
    bool search(string &word,int start,int count) {
        Trie* p=this;
        int word_size=word.size();
        for (int i=start;i<word_size;++i)
        {
            if (p->arc[word.at(i)-'a']==NULL)
                return false;
            else
            {
                p=p->arc[word.at(i)-'a'];
                if (p->is_leaf)
                {
                    if (i==word_size-1)
                        return count>=1;
                    if (search(word,i+1,count+1))
                        return true;
                }
            }
        }
        //无效return
        return false;
    }

};
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie key;
        for (string &i:words)
            key.insert(i);
        vector<string> ans;
        for (string &i:words)
            if (key.search(i,0,0))
                ans.push_back(i);
        return ans;
    }
};
