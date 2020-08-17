/*
* 补充题目：sentence中的每个单词是替换成词根，这个词根：词根+一个词=继承词，即词根一定是前缀
* 那么只需要把dict中的单词用字典树trie存起来
* 之后用sentence中的每个单词去遍历字典树，找到最短的前缀或者遍历完为止即可
* 这里改进了一下字典树的search更加适合本题
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
    string search_root(string &word) {
        Trie* p=this;
        int length=0;
        for (char &i:word)
            if (p->arc[i-'a']==NULL)
                return word;
            else if (p->arc[i-'a']->is_leaf)
            {
                ++length;
                return word.substr(0,length);
            }
            else
            {
                p=p->arc[i-'a'];
                ++length;
            }
        return word;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie tree;
        for (string &i:dict)
            tree.insert(i);
        string ans;
        stringstream ss;
        ss << sentence;
        string word;
        while (ss >> word)
            ans+=tree.search_root(word)+" ";
        ans.pop_back();
        return ans;
    }
};
