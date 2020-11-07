bool already_build=false;
const int MAXN=10001;
int cnt[MAXN];
void build_cnt()
{
    if (already_build)
        return;
    already_build=true;
    for (int i=0;i<MAXN;++i)
    {
        int n=i;
        int res=0;
        while(n!=0)
        {
            n&=n-1;
            ++res;
        }
        cnt[i]=res;
    }
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
