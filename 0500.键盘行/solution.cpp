class Solution {
    vector<unordered_set<char>> helper;
public:
    vector<string> findWords(vector<string>& words) {
        get_helper();
        vector<string> ans;
        for (string &i:words)
        {
            int pos=-1;
            bool judge=true;
            if (i.size()==1)
            {
                ans.push_back(i);
                continue;
            }
            for (char j:i)
            {
                if (j>='A' && j<='Z')
                    j=char(j+('a'-'A'));
                int k;
                for (k=0;k<3;++k)
                    if (helper.at(k).find(j)!=helper.at(k).end())
                        break;
                if (pos==-1)
                    pos=k;
                else if (pos!=k)
                {
                    judge=false;
                    break;
                }
            }
            if (judge)
                ans.push_back(i);
        }
        return ans;
    }
    void get_helper()
    {
        if (!helper.empty())
            return;
        helper.push_back(unordered_set<char>{'q','w','e','r','t','y','u','i','o','p'});
        helper.push_back(unordered_set<char>{'a','s','d','f','g','h','j','k','l'});
        helper.push_back(unordered_set<char>{'z','x','c','v','b','n','m'});
    }
};
