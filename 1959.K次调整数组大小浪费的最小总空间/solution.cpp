const int MAXN=200;
int dp[MAXN][MAXN][MAXN];
int mi[MAXN][MAXN];
class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(dp,0x3f,sizeof(dp));
        memset(mi,0x3f,sizeof(mi));
        int sz=nums.size();
        set<int> st(nums.begin(),nums.end());
        vector<int> vec(st.begin(),st.end());
        int vsz=vec.size();
        for (int a=0;a<vsz;a++) {
            if (vec.at(a)>=nums.at(0)) {
                dp[0][0][a]=vec.at(a)-nums.at(0);
                mi[0][0]=min(mi[0][0],dp[0][0][a]);
            }
        }
        for (int i=1;i<sz;i++) {
            int cur=nums.at(i);
            for (int j=0;j<=i && j<=k;j++) {
                for (int a=0;a<vsz;a++) {
                    int n=vec.at(a);
                    if (n<cur) {
                        continue;
                    }
                    if (i-1>=j && i-1>=0) {
                        dp[i][j][a]=min(dp[i][j][a],dp[i-1][j][a]+n-cur);
                    }
                    if (i-1>=j-1 && i-1>=0 && j-1>=0) {
                        dp[i][j][a]=min(dp[i][j][a],mi[i-1][j-1]+n-cur);
                    }
                    mi[i][j]=min(mi[i][j],dp[i][j][a]);
                }
            }
        }
        return mi[sz-1][k];
    }
};