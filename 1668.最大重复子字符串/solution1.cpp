class Solution {
public:
    int maxRepeating(string s, string w) {
        int ans=0;
        int s_size=s.size();
        int w_size=w.size();
        int i=0;
        for (int l=0;l<s_size;++l)
        {
            if (s.at(l)==w.at(0))
            {
                int st=l;
                int i=l;
                int j=0;
                while (i<s_size && s.at(i)==w.at(j))
                {
                    ++i;
                    ++j;
                    j= j==w_size ? 0 : j;
                }
                ans=max(ans,(i-st)/w_size);
            }
        }
        return ans;
    }
};
