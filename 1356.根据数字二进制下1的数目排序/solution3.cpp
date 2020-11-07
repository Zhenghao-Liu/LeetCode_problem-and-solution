bool already_build=false;
const int MAXN=10001;
int cnt[MAXN];
void build_cnt()
{
    if (already_build)
        return;
    already_build=true;
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<MAXN;++i)
        cnt[i]=cnt[i>>1]+(i&1);
}
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        build_cnt();
        sort(arr.begin(),arr.end(),[](const int &A,const int &B){
            return cnt[A]==cnt[B] ? A<B : cnt[A]<cnt[B];
        });
        return arr;
    }
};
