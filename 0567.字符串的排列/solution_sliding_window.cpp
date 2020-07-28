//s1的排列之一是s2的子串，那么即是滑窗，窗口大小为s1.size()时，s2窗口内字母构成和数量和s1的一样
class Solution {
    vector<int> s1_count;
    vector<int> s2_count;
public:
    bool checkInclusion(string s1, string s2) {
        int s1_size=s1.size(),s2_size=s2.size();
        if (s1_size>s2_size)
            return false;
        s1_count=vector<int>(26,0);
        s2_count=vector<int>(26,0);
        for (int i=0;i<s1_size;++i)
        {
            ++s1_count.at(s1.at(i)-'a');
            ++s2_count.at(s2.at(i)-'a');
        }
        if (s1_count==s2_count)
            return true;
        for (int i=s1_size;i<s2_size;++i)
        {
            ++s2_count.at(s2.at(i)-'a');
            --s2_count.at(s2.at(i-s1_size)-'a');
            if (s1_count==s2_count)
                return true;
        }
        return false;
    }
};
