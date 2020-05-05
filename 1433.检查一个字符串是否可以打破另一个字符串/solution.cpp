class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int length=s1.size();
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool judge_break=false;
        for (int i=0;i<length;++i)
            if (s1.at(i)>=s2.at(i))
                continue;
            else
            {
                judge_break=true;
                break;
            }
        if (!judge_break)
            return true;
        judge_break=false;
        for (int i=0;i<length;++i)
            if (s1.at(i)<=s2.at(i))
                continue;
            else
            {
                judge_break=true;
                break;
            }
        if (!judge_break)
            return true;
        return false;
    }
};
