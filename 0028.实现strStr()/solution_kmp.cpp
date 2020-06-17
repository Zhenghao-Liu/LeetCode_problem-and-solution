/**
* [KMP视频1](https://www.bilibili.com/video/BV1Px411z7Yo/)
* [KMP视频2](https://www.bilibili.com/video/BV1hW411a7ys/)
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        return kmp(haystack,needle);
    }
    int kmp(string &T,string &P)
    {
        //T.find(P);
        int T_size=T.size(),P_size=P.size();
        if (T_size<P_size)
            return -1;
        if (P.empty())
            return 0;
        vector<int> prefix(P_size,0);
        get_prefix(P,prefix,P_size);
        become_prefix_table(prefix,P_size);
        //i指向T，j指向P
        int i=0,j=0;
        while (i<T_size)
        {
            //剩下字符数都不够了，自然是不可能匹配的，剪枝
            if (P_size-j>T_size-i)
                return -1;
            if (T.at(i)==P.at(j))
            {
                ++i;
                ++j;
            }
            else
            {
                j=prefix.at(j);
                if (j==-1)
                {
                    j=0;
                    ++i;
                }
            }
            //匹配成功
            if (j==P_size)
                return i-P_size;
        }
        return -1;
    }
    void get_prefix(string &P,vector<int> &prefix,int P_size)
    {
        prefix.at(0)=0;
        int len=0;
        int i=1;
        while (i<P_size)
        {
            if (P.at(i)==P.at(len))
            {
                ++len;
                prefix.at(i)=len;
                ++i;
            }
            //else if (P.at(i)!=P.at(len))
            else
            {
                if (len>0)
                {
                    len=prefix.at(len-1);
                }
                else
                {
                    prefix.at(i)=0;
                    ++i;
                }
            }
        }
    }
    void become_prefix_table(vector<int> &prefix,int size)
    {
        for (int i=size-1;i>0;--i)
            prefix.at(i)=prefix.at(i-1);
        prefix.at(0)=-1;
    }
};
