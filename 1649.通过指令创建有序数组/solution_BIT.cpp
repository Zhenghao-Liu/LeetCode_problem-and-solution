const int n=1e5;
const int MAXN=n+1;
int t[MAXN];
int num[MAXN];
class Solution {
    int mod=1e9+7;
public:
    int createSortedArray(vector<int>& instructions) {
        memset(t,0,sizeof(t));
        memset(num,0,sizeof(num));
        int size=0;
        long long ans=0;
        for (int i:instructions)
        {
            int less=ask(i-1);
            int greater=size-less-num[i];
            ans+=min(less,greater);
            ans%=mod;
            ++size;
            ++num[i];
            add(i,1);
        }
        return ans;
    }
    int lowbit(int x)
    {
        return x&(-x);
    }
    void add(int x,int k)
    {
        for (;x<=n;x+=lowbit(x))
            t[x]+=k;
    }
    int ask(int x)
    {
        int ans=0;
        for (;x>0;x-=lowbit(x))
            ans+=t[x];
        return ans;
    }
};
