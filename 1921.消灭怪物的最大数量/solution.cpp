const int MAXN=1e5+5;
int cnt[MAXN];
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        memset(cnt,0,sizeof(cnt));
        int sz=dist.size();
        for (int i=0;i<sz;i++) {
            int cur=dist.at(i)/speed.at(i);
            if (cur*speed.at(i)!=dist.at(i)) {
                cur++;
            }
            cnt[cur]++;
        }
        int sco=0;
        int ans=0;
        for (int i=0;i<MAXN;i++) {
            if (cnt[i]==0) {
                sco++;
                continue;
            }
            ans+=min(cnt[i],sco);
            sco-=cnt[i];
            if (sco<0) {
                return ans;
            }
            sco++;
        }
        return ans;
    }
};