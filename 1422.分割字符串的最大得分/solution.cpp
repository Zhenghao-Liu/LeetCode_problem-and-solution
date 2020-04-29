class Solution {
public:
    int maxScore(string s) {
        int one=0;
        for (char &i:s)
            if (i=='1')
                ++one;
        int ans=INT_MIN;
        int zero=0;
        for (int i=0;i<s.size()-1;++i)
            if (s.at(i)=='0')
            {
                ++zero;
                ans=max(ans,zero+one);
            }
            else
            {
                --one;
                ans=max(ans,zero+one);
            }
        return ans;
            
    }
};
