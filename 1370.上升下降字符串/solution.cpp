class Solution {
public:
    string sortString(string s) {
        int cnt[26]={0};
        for (char i:s)
            ++cnt[i-'a'];
        int s_size=s.size();
        string ans;
        while ((int)ans.size()<s_size)
        {
            for (int i=0;i<26;++i)
                if (cnt[i]!=0)
                {
                    --cnt[i];
                    ans+=char(i+'a');
                }
            for (int i=25;i>=0;--i)
                if (cnt[i]!=0)
                {
                    --cnt[i];
                    ans+=char(i+'a');
                }
        }
        return ans;
    }
};
