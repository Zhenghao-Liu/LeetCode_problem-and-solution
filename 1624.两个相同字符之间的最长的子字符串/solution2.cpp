class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int start[26];
        memset(start,0x3f,sizeof(start));
        int size=s.size();
        int INF=0x3f3f3f3f;
        int ans=-1;
        for (int i=0;i<size;++i)
        {
            int idx=s.at(i)-'a';
            if (start[idx]==INF)
                start[idx]=i;
            else
                ans=max(ans,i-start[idx]-1);
        }
        return ans;
    }
};
