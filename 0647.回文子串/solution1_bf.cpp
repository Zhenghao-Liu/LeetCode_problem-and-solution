//暴力枚举，改成了char*优化复杂度
class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        int s_size=s.size();
        char * c=new char[s_size+1];
        strcpy(c,s.c_str());
        for (int i=0;i<s_size;++i)
        {
            char *start=c+i;
            for (int j=i;j<s_size;++j)
                if (judge_palindrome(start,c+j))
                    ++ans;
        }
        delete []c;
        return ans;
    }
    bool judge_palindrome(char *start,char *end)
    {
        while (start<end)
        {
            if (*start!=*end)
                return false;
            ++start;
            --end;
        }
        return true;
    }
};
