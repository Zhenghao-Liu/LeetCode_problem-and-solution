const int MAXN=30;
// 0是默认，-1是false，1是true
int dp[MAXN][MAXN][MAXN+1];
const int UP=26;
int cnt1[UP],cnt2[UP];
class Solution {
    int sz;
    string s1,s2;
public:
    bool isScramble(string s1, string s2) {
        memset(dp,0,sizeof(dp));
        this->sz=s1.size();
        this->s1=s1;
        this->s2=s2;
        return dfs(0,0,sz)==1;
    }
    int dfs(int iSt,int jSt,int len) {
        if (dp[iSt][jSt][len]!=0) {
            return dp[iSt][jSt][len];
        }
        string ss1=s1.substr(iSt,len),ss2=s2.substr(jSt,len);
        if (ss1==ss2) {
            dp[iSt][jSt][len]=1;
            return dp[iSt][jSt][len];
        }
        if (!helper(ss1,ss2,len)) {
            dp[iSt][jSt][len]=-1;
            return dp[iSt][jSt][len];
        }
        for (int k=1;k<len;k++) {
            if (dfs(iSt,jSt,k)==1 && dfs(iSt+k,jSt+k,len-k)==1) {
                dp[iSt][jSt][len]=1;
                return dp[iSt][jSt][len];
            }
            if (dfs(iSt,jSt+len-k,k)==1 && dfs(iSt+k,jSt,len-k)==1) {
                dp[iSt][jSt][len]=1;
                return dp[iSt][jSt][len];
            }
        }
        dp[iSt][jSt][len]=-1;
        return dp[iSt][jSt][len];
    }
    bool helper(string &ss1,string &ss2,int len) {
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));
        for (int i=0;i<len;i++) {
            cnt1[ss1.at(i)-'a']++;
            cnt2[ss2.at(i)-'a']++;
        }
        for (int i=0;i<UP;i++) {
            if (cnt1[i]!=cnt2[i]) {
                return false;
            }
        }
        return true;
    }
};