class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int left[26];
        int right[26];
        memset(left,0x3f,sizeof(left));
        memset(right,0x3f,sizeof(right));
        int size=s.size();
        int INF=0x3f3f3f3f;
        for (int i=0;i<size;++i)
        {
            int c=s.at(i)-'a';
            if (left[c]==INF)
                left[c]=i;
        }
        for (int i=size-1;i>=0;--i)
        {
            int c=s.at(i)-'a';
            if (right[c]==INF)
                right[c]=i;
        }
        int ans=-1;
        for (int i=0;i<26;++i)
            if (left[i]!=INF && right[i]!=INF && left[i]!=right[i])
            {
                int d=right[i]-left[i]-1;
                ans=max(ans,d);
            }
        return ans;
    }
};
