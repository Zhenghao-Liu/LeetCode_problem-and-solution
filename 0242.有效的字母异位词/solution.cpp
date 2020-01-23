//最佳解法
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> helper(26,0);
        if (s.size()!=t.size())
            return false;
        int size=s.size();
        for (int i=0;i<size;++i)
        {
            ++helper.at(s.at(i)-'a');
            --helper.at(t.at(i)-'a');
        }
        for (int &i:helper)
            if (i!=0)
                return false;
        return true;
    }
};
