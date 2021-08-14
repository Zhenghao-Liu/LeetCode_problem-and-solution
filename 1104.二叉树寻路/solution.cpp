typedef pair<int,int> pii;
bool already=false;
const int MAXN=21;
int num[MAXN];
void build_pow() {
    if (already) {
        return;
    }
    already=true;
    num[0]=1;
    for (int i=1;i<MAXN;i++) {
        num[i]=2*num[i-1];
    }
}
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        build_pow();
        int lev=1;
        auto [st,ed]=sted(lev);
        while (!(st<=label && label<=ed)) {
            lev++;
            pii range=sted(lev);
            st=range.first;
            ed=range.second;
        }
        vector<int> ans;
        while (lev>1) {
            ans.push_back(label);
            auto [st,ed]=sted(lev);
            int cursz=curcnt(lev);
            auto [upst,uped]=sted(lev-1);
            int upsz=curcnt(lev-1);
            label=uped-(label-st)/2;
            lev--;
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
    pii sted(int lev) {
        return {num[lev-1],num[lev]-1};
    }
    int curcnt(int lev) {
        return num[lev-1];
    }
};