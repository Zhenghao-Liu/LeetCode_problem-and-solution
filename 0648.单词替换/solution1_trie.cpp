/*
* 补充题目：sentence中的每个单词是替换成词根，这个词根：词根+一个词=继承词，即词根一定是前缀
* 那么只需要把dict中的单词用字典树trie存起来
* 之后用sentence中的每个单词去遍历字典树，找到最短的前缀或者遍历完为止即可
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
    bool search(string &word) {
        Trie* p=this;
        for (char &i:word)
            if (p->arc[i-'a']==NULL)
                return false;
            else
                p=p->arc[i-'a'];
        return p->is_leaf;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie tree;
        for (string &i:dict)
            tree.insert(i);
        string ans;
        int sentence_size=sentence.size();
        string word;
        for (int i=0;i<=sentence_size;++i)
        {
            if (i==sentence_size || sentence.at(i)==' ')
            {
                ans+=word+" ";
                word.clear();
                continue;
            }
            word+=sentence.at(i);
            if (tree.search(word))
            {
                ans+=word+" ";
                word.clear();
                while (i<sentence_size && sentence.at(i)!=' ')
                    ++i;
            }
        }
        ans.pop_back();
        return ans;
    }
};
