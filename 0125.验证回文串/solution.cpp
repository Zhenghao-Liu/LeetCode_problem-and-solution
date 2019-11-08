class Solution {
public:
    bool isPalindrome(string s) {
        int s_size=s.size(),left=0,right=s_size-1;
        if (s_size<2)
            return true;
        while(left<=right)
        {
            if ((s.at(left)<='z' && s.at(left)>='a') || (s.at(left)<='Z' && s.at(left)>='A') || (s.at(left)<='9' && s.at(left)>='0'));
            else
            {
                ++left;
                continue;
            } 
            if ((s.at(right)<='z' && s.at(right)>='a') || (s.at(right)<='Z' && s.at(right)>='A') || (s.at(right)<='9' && s.at(right)>='0'));
            else
            {
                --right;
                continue;
            }
            if (tolower(s.at(left))==tolower(s.at(right)))
            {
                ++left;
                --right;
            }
            else
                return false;
        }
        return true;
    }
};
