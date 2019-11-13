//不建议用，substr太耗时间了
class Solution {
public:
    int minCut(string s) {
        if (isPalindrome(s))
            return 0;
        int s_size=s.size();
        vector<int> dp(s_size,0);
        string temporary;
        for (int i=1;i<s_size;++i)
        {
            temporary=s.substr(0,i+1);
            if (isPalindrome(temporary))
                continue;
            dp.at(i)=i;
            for (int j=1;j<=i;++j)
            {
                temporary=s.substr(j,i-j+1);
                if (isPalindrome(temporary))
                    dp.at(i)=min(dp.at(i),dp.at(j-1)+1);
            }    
        }
        return dp.at(s_size-1);
    }
    bool isPalindrome(string& s) {
        int left=0,right=s.size()-1;
        while(left<=right)
            if (tolower(s.at(left))==tolower(s.at(right)))
            {
                ++left;
                --right;
            }
            else
                return false;
        return true;
    }
};
