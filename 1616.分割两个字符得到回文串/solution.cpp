class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int size=a.size();
        int al=0,ar=size-1;
        int bl=0,br=size-1;
        if (che2(a,al,ar,-1) || che2(b,bl,br,-1)) return true;
        for (int i=0;i<size;++i)
        {
            swap(a.at(i),b.at(i));
            if (che2(a,al,ar,i) || che2(b,bl,br,i)) return true;
        }
        return false;
    }
    bool che2(string &s,int &l,int &r,int s_idx)
    {
        if ((s_idx<l || s_idx>r) && s_idx!=-1)
        {
            int j=(int)s.size()-s_idx-1;
            if (s.at(s_idx)!=s.at(j))
            {
                l=min(s_idx,j);
                r=max(s_idx,j);
            }
        }
        while (l<r)
            if (s.at(l)==s.at(r)) ++l,--r;
            else break;
        return l>=r;
    }
};
