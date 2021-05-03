// 贪心的去取最多的可能性
const int MAXN=1000;
int cnt[MAXN];
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        memset(cnt,0,sizeof(cnt));
        for (int i:answers) {
            cnt[i]++;
        }
        int ans=0;
        ans+=cnt[0];
        for (int i=1;i<MAXN;i++) {
            ans+=cnt[i]/(i+1)*(i+1);
            if ((cnt[i]%(i+1))!=0) {
                ans+=i+1;
            }
        }
        return ans;
    }
};