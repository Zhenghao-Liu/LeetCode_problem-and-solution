// __builtin_popcount
const int MAXN=1<<16;
int dp[MAXN+1];
int cnt[MAXN+1];
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int sz=arr.size();
        vector<int> vec(sz);
        for (int i=0;i<sz;i++) {
            for (char c:arr.at(i)) {
                vec.at(i)|=1<<(c-'a');
            }
        }
        memset(dp,0,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        int ALL=(1<<sz)-1;
        int ans=0;
        for (int i=1;i<=ALL;i++) {
            for (int j=0;j<sz;j++) {
                int key=1<<j;
                if ((key&i)==0) {
                    continue;
                }
                int old=key^i;
                dp[i]=vec.at(j)|dp[old];
                cnt[i]=arr.at(j).size()+cnt[old];
                if (cnt[i]==__builtin_popcount(dp[i])) {
                    ans=max(ans,cnt[i]);
                }
                break;
            }
        }
        return ans;
    }
};