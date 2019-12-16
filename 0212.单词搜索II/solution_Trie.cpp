//把words中所有单词存到Trie中，在board中DFS构成单词然后在Trie中search
class Trie {
private:
    bool is_leaf=false;
    //数组初始化只有全为0才能这样写
    Trie* arc[26]={NULL};
public:
    /** Initialize your data structure here. */
    Trie() {}
    
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
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string &prefix) {
        Trie* p=this;
        for (char &i:prefix)
            if (p->arc[i-'a']==NULL)
                return false;
            else
                p=p->arc[i-'a'];
        return true;
    }

};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row=board.size();
        if (row<1 || words.empty())
            return {};
        int column=board.at(0).size();
        Trie Trie_words;
        int words_maxsize=0;
        for (string &i:words)
        {
            Trie_words.insert(i);
            //注意i.size()返回的是unsigned int
            if (words_maxsize<i.size())
                words_maxsize=i.size();
        }
        vector<string> answer;
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                dfs(board,answer,Trie_words,row,column,words_maxsize,"",i,j);
        return answer;
    }
    void dfs(vector<vector<char>> &board,vector<string>& answer,Trie& Trie_words,const int& row,const int& column,const int& words_maxsize,string s,int i,int j)
    {
        //剪枝1
        if (s.size()>=words_maxsize || board.at(i).at(j)=='!')
            return;
        s.append(1,board.at(i).at(j));
        char temp=board.at(i).at(j);
        board.at(i).at(j)='!';
        //有可能DFS出现两次同样的单词
        if (Trie_words.search(s) && find(answer.begin(),answer.end(),s)==answer.end())
            answer.push_back(s);
        //剪枝2
        if (!Trie_words.startsWith(s))
        {
            //一定要记得恢复访问过的标记
            board.at(i).at(j)=temp;
            return;
        }  
        if (i+1<row)
            dfs(board,answer,Trie_words,row,column,words_maxsize,s,i+1,j);
        if (i-1>-1)
            dfs(board,answer,Trie_words,row,column,words_maxsize,s,i-1,j);
        if (j+1<column)
            dfs(board,answer,Trie_words,row,column,words_maxsize,s,i,j+1);
        if (j-1>-1)
            dfs(board,answer,Trie_words,row,column,words_maxsize,s,i,j-1);
        board.at(i).at(j)=temp;
    }
};