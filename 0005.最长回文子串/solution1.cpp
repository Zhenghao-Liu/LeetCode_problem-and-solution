class Solution {
public:
    string longestPalindrome(string s) {
        int length=s.size();
        if (length==0 || length==1)
            return s;
        int start=0,end=0,len1=0,len2=0;
        for (int i=0;i<length;++i)
        {
            len1=find_length(s,i,i);
            len2=find_length(s,i,i+1);
            len1=len1>len2?len1:len2;
            if (len1>(end-start+1))
            {
                end=i+len1/2;
                start=end+1-len1;
            }
        }
        return s.substr(start,end-start+1);
    }
    int find_length(string s,int i,int j)
    {
        int length=s.size();
        while ( i>=0 && j<length && s.at(i)==s.at(j))
        {
            --i;
            ++j;
        }
        return (j-i-1);
    }
};
