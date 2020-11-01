const int MAXN=2001;
int cnt[MAXN];
const int MAXL=1001;
int ans[MAXL];
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        memset(cnt,0,sizeof(cnt));
        for (int i:arr)
            ++cnt[i+1000];
        memset(ans,0,sizeof(ans));
        for (int i:cnt)
            if (i!=0)
                ++ans[i];
        for (int i=1;i<MAXL;++i)
            if (ans[i]!=0 && ans[i]>1)
                return false;
        return true;
    }
};
