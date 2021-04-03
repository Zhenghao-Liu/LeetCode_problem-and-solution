class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int sz1=text1.size(),sz2=text2.size();
        vector<vector<int>> dp(sz1,vector<int>(sz2,0));
        dp.at(0).at(0)= text1.at(0)==text2.at(0) ? 1 : 0;
        for (int j=1;j<sz2;j++) {
            if (text1.at(0)==text2.at(j)) {
                dp.at(0).at(j)=1;
            } else {
                dp.at(0).at(j)=dp.at(0).at(j-1);
            }
        }
        for (int i=1;i<sz1;i++) {
            if (text1.at(i)==text2.at(0)) {
                dp.at(i).at(0)=1;
            } else {
                dp.at(i).at(0)=dp.at(i-1).at(0);
            }
        }
        for (int i=1;i<sz1;i++) {
            for (int j=1;j<sz2;j++) {
                if (text1.at(i)==text2.at(j)) {
                    dp.at(i).at(j)=max(dp.at(i-1).at(j-1)+1,max(dp.at(i-1).at(j),dp.at(i).at(j-1)));
                } else {
                    dp.at(i).at(j)=max(dp.at(i-1).at(j),dp.at(i).at(j-1));
                }
            }
        }
        return dp.at(sz1-1).at(sz2-1);
    }
};