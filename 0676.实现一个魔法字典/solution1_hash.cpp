//将单词按照长度分组，然后再用searchWord与对应长度的单词比较差别
class MagicDictionary {
    //key存长度，value存长度为key的单词
    unordered_map<int,vector<string>> dict;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        dict.clear();
    }
    
    void buildDict(vector<string> dictionary) {
        for (string &i:dictionary)
        {
            int size=i.size();
            dict[size].push_back(i);
        }
    }
    
    bool search(string searchWord) {
        int size=searchWord.size();
        if (dict.find(size)==dict.end())
            return false;
        for (string &i:dict.at(size))
        {
            int diff=0;
            for (int j=0;j<size;++j)
            {
                if (searchWord.at(j)!=i.at(j))
                    ++diff;
                if (diff>=2)
                    break;
            }
            if (diff==1)
                return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
