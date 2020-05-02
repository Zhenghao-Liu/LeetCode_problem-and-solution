class Solution {
public:
    string decodeString(string s) {
        int s_size=s.size();
        int index=0;
        return decodeString_helper(s,index,s_size);
    }
    string decodeString_helper(string &s,int &index,const int & s_size)
    {
        string window;
        string num;
        for (;index<s_size;++index)
            if (s.at(index)>='0' && s.at(index)<='9')
                num+=s.at(index);
            else if (s.at(index)=='[')
            {
                ++index;
                string temp=decodeString_helper(s,index,s_size);
                for (int j=stoi(num);j>0;--j)
                    window+=temp;
                num.clear();
            }
            else if (s.at(index)==']')
                return window;
            else
                window+=s.at(index);
        return window;
    }
};
