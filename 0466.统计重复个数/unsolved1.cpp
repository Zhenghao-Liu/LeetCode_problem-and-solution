//构建好S1 S2，匹配S1中有几个S2
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        string ss1,ss2;
        int ss1_size=s1.size()*n1,ss2_size=s2.size()*n2;
        ss1.reserve(ss1_size);
        ss2.reserve(ss2_size);
        for (int i=0;i<n1;++i)
            ss1+=s1;
        for (int i=0;i<n2;++i)
            ss2+=s2;
        int M=0;
        int j=0;
        for (int i=0;i<ss1_size;++i)
            if (ss1.at(i)==ss2.at(j))
            {
                ++j;
                if (j==ss2_size)
                {
                    j=0;
                    ++M;
                }
            }
        return M;
    }
};
