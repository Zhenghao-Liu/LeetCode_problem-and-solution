//真正替换的只用a b c就够了
class Solution {
public:
    string modifyString(string s) {
        int size=s.size();
        for (int i=0;i<size;++i)
        {
            if (s.at(i)=='?')
            {
                char l=i-1>=0 ? s.at(i-1) : '!';
                char r=i+1<size ? s.at(i+1) : '!';
                for (char j='a';j<='z';++j)
                    if (j!=l && j!=r)
                    {
                        s.at(i)=j;
                        break;
                    }
            }
        }
        return s;
    }
};
