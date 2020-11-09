//搬运到最近的空位置，也可以用集合判别是否出现
int show[26];
const int MAXN=1e5+1;
int cnt[MAXN];
class Solution {
public:
    int minDeletions(string s) {
        memset(show,0,sizeof(show));
        for (char i:s)
            ++show[i-'a'];
        memset(cnt,0,sizeof(cnt));
        for (int i=0;i<26;++i)
            if (show[i]!=0)
                ++cnt[show[i]];
        int zero=0;
        int ans=0;
        for (int i=1;i<MAXN;++i)
            if (cnt[i]==0)
                zero=i;
            else if (cnt[i]>1)
            {
                while (cnt[i]>1)
                {
                    --cnt[i];
                    ans+=i-zero;
                    if (zero!=0)
                        ++cnt[zero];
                    while (zero>0 && cnt[zero]!=0)
                        --zero;
                }
            }
        return ans;
    }
};
