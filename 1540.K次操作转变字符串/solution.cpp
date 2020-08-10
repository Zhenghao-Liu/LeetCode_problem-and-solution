/*
* 设字符a编导字符b需要i步，那么说明i+26k步也是可以实现这个变化的（这里k是个常数，不是题目的k）
* 且对于别的字符需要变j步且j!=i的话，那么j+26k!=i+26k，
* 即最小变换步数不同的话，那么这些变换是没有关系的，即只用考虑那些最小变换相同步数的情况
* 即需要满足所有情况的最小变换步数i，都要能够做到k>=i+26*（共有几个变换是最小变换步数为i的-1）
*/
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size()!=t.size())
            return false;
        vector<int> count(26);
        int size=s.size();
        for (int i=0;i<size;++i)
            if (s.at(i)!=t.at(i))
                ++count.at((t.at(i)-s.at(i)+26)%26);
        for (int i=0;i<26;++i)
        {
            if (count.at(i)!=0)
            {
                int a=count.at(i)-1;
                if (a*26+i<=k)
                    continue;
                else
                    return false;
            }
        }
        return true;
    }
};
