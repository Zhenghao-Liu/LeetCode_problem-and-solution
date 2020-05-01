//直接双指针
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_size=s.size();
        if (s_size==0)
            return true;
        int index=0;
        for (char &i:t)
        {
            if (s.at(index)==i)
                ++index;
            if (index==s_size)
                return true;
        }
        return false;
    }
};
