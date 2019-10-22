class Solution {
public:
    bool isMatch(string s, string p) {
    return isMatch(s.c_str(),p.c_str());
} 
    bool isMatch(const char *s,const char *p)
    {
	    if (*p==0)
            return *s==0;
        bool judge=(*s!=0 && (*s==*p || *p=='.'));
        if ( judge && *(p+1)=='*')
            return (isMatch(s+1,p) || isMatch(s+1,p+2) || isMatch(s,p+2));
        else if (judge)
            return isMatch(s+1,p+1);
        else if ( *s!=0 && *s!=*p && *(p+1)=='*' )
            return isMatch(s,p+2);
        else if (*s==0 && *(p+1)=='*')
            return isMatch(s,p+2);
        return false;
    }
};
