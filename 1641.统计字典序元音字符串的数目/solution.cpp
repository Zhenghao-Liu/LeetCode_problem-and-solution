class Solution {
public:
    int countVowelStrings(int n) {
        int cnt[5];
        for (int i=0;i<5;++i)
            cnt[i]=1;
        while (n>1)
        {
            int nxt[5]={0};
            for (int i=0;i<5;++i)
                for (int j=i;j<5;++j)
                    nxt[j]+=cnt[i];
            for (int i=0;i<5;++i)
                cnt[i]=nxt[i];
            --n;
        }
        return accumulate(cnt,cnt+5,0);
    }
};
