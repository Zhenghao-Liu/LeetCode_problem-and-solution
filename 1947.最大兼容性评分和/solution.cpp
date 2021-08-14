const int MAXN=8;
int dp[MAXN][1<<MAXN];
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& stu, vector<vector<int>>& men) {
        int m=stu.size(),n=stu.at(0).size();
        vector<int> st(m),me(m);
        for (int i=0;i<m;i++) {
            int num=0;
            for (int j:stu.at(i)) {
                num|=j;
                num<<=1;
            }
            num>>=1;
            st.at(i)=num;

            num=0;
            for (int j:men.at(i)) {
                num|=j;
                num<<=1;
            }
            num>>=1;
            me.at(i)=num;
            
            // cout << st.at(i) << ' ' << me.at(i) << endl;
        }
        memset(dp,0,sizeof(dp));
        int all=(1<<m)-1;
        for (int i=0;i<m;i++) {
            for (int j=0;j<=all;j++) {
                if (__builtin_popcount(j)!=i) {
                    continue;
                }
                for (int k=0;k<m;k++) {
                    if (((1<<k)&j)==0) {
                        int prev=i!=0 ? dp[i-1][j] : 0;
                        int cur=st.at(i)^me.at(k);
                        cur=n-__builtin_popcount(cur);
                        // cout << i << ' ' << j << ' ' <<  k << ' ' << prev<<' ' << cur << endl;
                        dp[i][j|(1<<k)]=max(dp[i][j|(1<<k)],prev+cur);
                    }
                }
            }
        }
        return dp[m-1][all];
    }
};