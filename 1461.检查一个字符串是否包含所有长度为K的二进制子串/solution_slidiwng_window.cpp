class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int s_size=s.size();
        if (s_size<=k)
            return false;
        vector<bool> helper(pow(2,k),false);
        int mask=1;
        for (int i=1;i<k;++i)
        {
            mask<<=1;
            mask|=1;
        }
        int window=0;
        for (int i=0;i<k;++i)
        {
            window<<=1;
            window|=s.at(i)-'0';
        }
        helper.at(window)=true;
        for (int i=k;i<s_size;++i)
        {
            window<<=1;
            window|=s.at(i)-'0';
            window&=mask;
            helper.at(window)=true;
        }
        for (bool i:helper)
            if (!i)
                return false;
        return true;
    }
};
