class WordDictionary {
    unordered_set<string> helper_set;
    unordered_set<int> helper_size;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        //因为是unordered_set，所以重复字符不会重复加入
        helper_set.insert(word);
        helper_size.insert(word.size());
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int word_size=word.size();
        if (helper_size.find(word_size)==helper_size.end())
            return false;
        bool judge;
        for (unordered_set<string>::iterator i=helper_set.begin();i!=helper_set.end();++i)
        {
            judge=true;
            if ((*i).size()==word_size)
            {
                for (int j=0;j<word_size;++j)
                    if (word.at(j)!='.' && word.at(j)!=(*i).at(j))
                    {
                        judge=false;
                        break;
                    }
                if (judge)
                    return true;
            }
        }
        return false;
    }
};
