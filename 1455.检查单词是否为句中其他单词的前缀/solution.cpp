class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> s;
        stringstream ss;
        ss << sentence;
        string temp;
        while (ss >> temp)
            s.push_back(temp);
        int size=s.size();
        int ans=-1;
        for (int i=0;i<size;++i)
            if (searchWord.size()<=s.at(i).size())
            {
                bool judge=true;
                int s_size=searchWord.size();
                for (int j=0;j<s_size;++j)
                    if (s.at(i).at(j)!=searchWord.at(j))
                    {
                        judge=false;
                        break;
                    }
                if (judge)
                {
                    ans=i+1;
                    break;
                }
                
            }
        return ans;
    }
};
