/*
 * 两个BIT
 * 一个维护个数
 * 一个维护总和
 * 用二分方式去找最小和最大
 * 注意BIT不是升序的，但是求和ask是升序的
 */
typedef long long ll;
const int MAXN=1e5+1;
ll cnt[MAXN];
ll nums[MAXN];
int lowbit(int x) {return x&(-x);}
void addCnt(int x,int k) {
    for (;x<=MAXN;x+=lowbit(x))
        cnt[x]+=k;
}
void addNums(int x,int k) {
    for (;x<=MAXN;x+=lowbit(x))
        nums[x]+=k;
}
ll askCnt(int x) {
    ll ans=0;
    for (;x>0;x-=lowbit(x))
        ans+=cnt[x];
    return ans;
}
ll askNums(int x) {
    ll ans=0;
    for (;x>0;x-=lowbit(x))
        ans+=nums[x];
    return ans;
}
class MKAverage {
    int m,k;
    ll sum;
    queue<int> que;
    int sz;
public:
    MKAverage(int m, int k) {
        memset(nums,0,sizeof(nums));
        memset(cnt,0,sizeof(cnt));
        this->m=m;
        this->k=k;
        this->sum=0;
        while (!que.empty()) {
            que.pop();
        }
        sz=0;
    }
    
    void addElement(int num) {
        sz++;
        sum+=num;
        que.push(num);
        addCnt(num,1);
        addNums(num,num);
        if (sz>m) {
            int pop=que.front();
            que.pop();
            addCnt(pop,-1);
            addNums(pop,-pop);
            sum-=pop;
        }
    }
    
    int calculateMKAverage() {
        ll ans=sum;
        if (sz<m) {
            return -1;
        }
        int l=1,r=MAXN-1;
        while (l<r) {
            int mid=l+(r-l)/2;
            int cur=askCnt(mid);
            if (cur>=k) {
                r=mid;
            } else {
                l=mid+1;
            }
        }
        ll miCnt=askCnt(l);
        ll miSum=askNums(l)-(miCnt-k)*l;
        l=1,r=MAXN-1;
        while (l<r) {
            int mid=l+(r-l-1)/2;
            int cur=m-askCnt(mid);
            if (cur<=k) {
                r=mid;
            } else {
                l=mid+1;
            }
        }
        ll mxCnt=askCnt(l);
        ll mxSum=sum-askNums(l)+(k-(m-mxCnt))*l;
        ans-=miSum+mxSum;
        return ans/(m-2*k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */