typedef long long ll;
const int MAXN=1e5+1;
ll cnt[MAXN];
ll sign[MAXN];
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        memset(cnt,0,sizeof(cnt));
        memset(sign,0,sizeof(sign));
        for (vector<int> &i:segments) {
            int a=i.at(0),b=i.at(1),c=i.at(2);
            cnt[a]+=c;
            cnt[b]-=c;
            sign[b]=1;
        }
        vector<vector<ll>> ans;
        ll cur=0,st=-1;
        for (int i=0;i<MAXN;i++) {
            ll ncur=cur+cnt[i];
            if (ncur!=cur || sign[i]==1) {
                if (cur!=0) {
                    ans.push_back({st,i,cur});                    
                }
                st=i;
            }
            cur=ncur;
        }
        return ans;
    }
};