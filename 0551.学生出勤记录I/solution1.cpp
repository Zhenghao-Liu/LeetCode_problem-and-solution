class Solution {
public:
    bool checkRecord(string s) {
        int count_A=0;
        int count_L=0;
        int s_size=s.size();
        for (int i=0;i<s_size;++i)
        {
            if (s.at(i)=='P')
                continue;
            if (s.at(i)=='A')
            {
                ++count_A;
                if (count_A>1)
                    return false;
            }
            //else if (s.at(i)=='L)
            else
            {
                int j;
                for (j=i;j<s_size;++j)
                    if (s.at(j)!='L')
                        break;
                if (j-i>2)
                    return false;
                i=j-1;
            }
        }
        return true;
    }
};
