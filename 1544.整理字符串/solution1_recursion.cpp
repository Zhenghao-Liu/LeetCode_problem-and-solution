class Solution {
public:
    string makeGood(string &s) {
        int size=s.size();
        for (int i=0;i<size;++i)
        {
            if (i+1<size && judge(s.at(i),s.at(i+1)))
            {
                s.erase(s.begin()+i,s.begin()+i+2);
                return makeGood(s);
            }
        }
        return s;
    }
    bool judge(char a,char b)
    {
        return a==b+'a'-'A' || b==a+'a'-'A';
    }
};
