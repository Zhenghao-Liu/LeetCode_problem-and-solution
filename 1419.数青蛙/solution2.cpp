class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int ans=0;
        int c,r,o,a,k;
        c=r=o=a=k=0;
        for (char &i:croakOfFrogs)
        {
            switch(i)
            {
                case 'c':++c;break;
                case 'r':++r;break;
                case 'o':++o;break;
                case 'a':++a;break;
                case 'k':++k;break;
                default:return -1;break;
            }
            if (!(c>=r && r>=o && o>=a && a>=k))
                return -1;
            ans=max(c,ans);
            if (i=='k')
            {
                --c;
                --r;
                --o;
                --a;
                --k;
            }
        }
        if (c!=0 || r!=0 || o!=0 || a!=0 || k!=0)
            return -1;
        return ans;
    }
};
