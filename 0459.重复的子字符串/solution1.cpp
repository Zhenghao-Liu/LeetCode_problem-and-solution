//暴力匹配，尝试是否是最小循环节
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int s_size=s.size();
        int limit=s_size/2;
        for (int i=1;i<=limit;++i)
        {
            if (s_size%i!=0)
                continue;
            int times=s_size/i-1;
            string key=s.substr(0,i),temp=key;
            while (times>0)
            {
                key+=temp;
                --times;
            }
            if (key==s)
                return true;
        }
        return false;
    }
};
