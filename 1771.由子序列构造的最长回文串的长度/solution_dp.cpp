class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s=word1+word2;
        return longestPalindromeSubseq(s,word1.size(),word2.size());
    }
    int longestPalindromeSubseq(string &s,int sz1,int sz2) {
        if (s.empty())
            return 0;
        int s_size=s.size();
        int ans=0;
        vector<vector<int>> dp(s_size,vector<int>(s_size,0));
        for (int i=0;i<s_size;++i)
            dp.at(i).at(i)=1;
        for (int i=s_size-2;i>=0;--i)
            for (int j=i+1;j<s_size;++j)
                if (s.at(i)==s.at(j)) {
                    dp.at(i).at(j)=2+dp.at(i+1).at(j-1);
                    if (i<sz1 && j>=sz1) {
                        ans=max(ans,dp.at(i).at(j));
                    }
                }
                else
                    dp.at(i).at(j)=max(dp.at(i+1).at(j),dp.at(i).at(j-1));
        
        return ans;
    }
};
