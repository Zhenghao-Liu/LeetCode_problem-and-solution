/*
* 从终点target返回遍历到起点0
* 记忆化dfs
* 从终点返回到起点有多种方法
  1. 直接全部步行
  2. 直接坐公交车
  3. 向前走几步再坐公交
  4. 向后走几步再坐公交
* 上述决策2可以归结到决策3的余数为0的情况，所以代码只用写3个方向
* 决策3：先向前步行几步，再坐公交车（包括了决策2）
  即A到cur，是A先乘公交车到达A*jmp，之后向后步行step1，到达cur
  A*jmp+step1=cur
  可以通过cur%jmp求得step1，通过cur/jmp求得A
* 决策4：先向后步行几步，再坐公交车
  即A到cur，是A先乘公交车到达A*jmp，之后向前步行step2，到达cur
  A*jmp-step2=cur
  即(A-1)*jmp+step3=cur，且step2+step3=jmp
  即可通过jmp-cur%jmp求得setp2，可通过cur/jmp+1求得A
* 还有就是不能中间取模，不然min就没有意义了，所以采用long long，最后取模
*/
typedef long long ll;
class Solution {
    ll mod=1e9+7;
    unordered_map<int,ll> memo;
    ll inc;
    ll dec;
    vector<int> jump;
    vector<int> cost;
public:
    int busRapidTransit(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
        memo.clear();
        this->inc=inc;
        this->dec=dec;
        this->jump=jump;
        this->cost=cost;
        return dfs(target)%mod;
    }
    ll dfs(int cur)
    {
        if (cur==0)
            return 0;
        if (memo.find(cur)!=memo.end())
            return memo.at(cur);
        //决策1：直接步行到起点
        ll ans=inc*cur;
        //从位置1回到位置0只有可能步行
        if (cur==1)
            return ans;
        int size=jump.size();
        for (int i=0;i<size;++i)
        {
            ll jmp=jump.at(i);
            ll cos=cost.at(i);
            //决策3：先向前步行几步，再坐公交车（包括了决策2）
            int step1=cur%jmp;
            int A=cur/jmp;
            //判断是不是直接往前走几步直接到终点，即根本不用做公交车
            //根本不用坐公交车在决策1讨论了
            if (cur-step1>0)
                ans=min(ans,step1*inc+cos+dfs(A));
            //决策4：先向后步行几步，再坐公交车
            //注意如果是可以直接搭公交，即根本不需要向前走再搭公交，那么自然也不用考虑向后走再搭公交
            if (step1>0)
            {
                int step2=jmp-cur%jmp;
                A=cur/jmp+1;
                ans=min(ans,step2*dec+cos+dfs(A));
            }
        }
        memo[cur]=ans;
        return ans;
    }
};
