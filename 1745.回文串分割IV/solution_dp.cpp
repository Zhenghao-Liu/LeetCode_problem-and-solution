// 2e3复杂度，先n2的dp求出dp[i][j]表示s[i]~s[j]左闭右闭是否是回文串，然后枚举三分回文串的起点即可
class Solution {
public:
    bool checkPartitioning(string s) {
        int sz=s.size();
        vector<vector<bool>> pal(sz,vector<bool>(sz,false));
        for (int i=sz-1;i>=0;i--) {
            for (int j=i;j<sz;j++) {
                if (s.at(i)==s.at(j) && (j-i<=1 || pal.at(i+1).at(j-1))) {
                    pal.at(i).at(j)=true;
                }
            }
        }
        for (int i=1;i<sz-1;i++) {
            for (int j=i+1;j<sz;j++) {
                if (pal.at(0).at(i-1) && pal.at(i).at(j-1) && pal.at(j).at(sz-1)) {
                    return true;
                }
            }
        }
        return false;
    }
};
