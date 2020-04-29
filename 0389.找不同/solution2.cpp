//转换成所有数出现了两次，只有目标出现了一次
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans=0;
        int s_size=s.size();
        for (int i=0;i<s_size;++i)
            ans=ans^s.at(i)^t.at(i);
        ans^=t.at(s_size);
        return ans;
    }
};
