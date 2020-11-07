//因为只有100，可以采用n^3的暴力方法
class Solution {
public:
    int countSubstrings(string s, string t) {
        int s_size=s.size();
        int t_size=t.size();
        int ans=0;
        for (int i=0;i<s_size;++i)
            for (int j=0;j<t_size;++j)
            {
                int l=i,r=j;
                int mis=0;
                while (l>=0 && r>=0 && s.at(l)==t.at(r))
                {
                    --l;
                    --r;
                }
                if (l>=0 && r>=0 && s.at(l)!=t.at(r))
                {
                    --l;
                    --r;
                    ++ans;
                }
                while (l>=0 && r>=0 && s.at(l)==t.at(r))
                {
                    --l;
                    --r;
                    ++ans;
                }
            }
        return ans;
    }
};
