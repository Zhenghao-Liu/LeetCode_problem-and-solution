/*
 * 设节点cur，有两个子树
   子树A的建筑顺序有Wa种，子树A有Na个节点
   子树B的建筑顺序有Wb种，子树B有Nb个节点
 * 首先可以先构建子树A，再构建子树B，那么这种情况的建筑顺序就有Wa*Wb种
   那如果是交叉构建呢，但仍要保证在同一棵子树内的相对顺序是不变的，所以就有了Comb(Na+Nb,Nb)种
 * 最后得出两个子树的总共构建方案是Wa*Wb*Comb(Na+Nb,Nb)，且当前节点一定是最后建的，所以方案不变
   且总节点个数是Na+Nb
 * 所以就可以dfs递归下去，如果一个节点没有子树，
   自然只有1种建筑顺序就是其本身，和共1个节点就是其本身
 * 涉及到Comb且1e5过大无法数组缓存，所以采用get_comb，注意取模涉及到除法，即逆元处理
 */
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;
ll quick_pow2_2(ll a,ll n)
{
    if (a==0) {
        return 0;
    }
    a%=mod;
    ll ans=1;
    while (n!=0) {
        if ((n&1)==1) {
            ans*=a;
            ans%=mod;
        }
        a*=a;
        a%=mod;
        n>>=1;
    }
    return ans;
}
ll mul_mod(ll a,ll b)
{
    return (a%mod)*(b%mod)%mod;
}
ll div_mod(ll a,ll b)
{
    //mod必须为质数
    return (a%mod)*quick_pow2_2(b,mod-2)%mod;
}
const int MAXN=1e5+1;
bool already_build=false;
ll factorial[MAXN];
void build_factorial() {
    if (already_build) {
        return;
    }
    already_build=true;
    factorial[0]=factorial[1]=1;
    for (int i=2;i<MAXN;i++) {
        factorial[i]=mul_mod(i,factorial[i-1]);
    }
}
//$C_{n}^{m}$即comb[n][m]
//上面是m，下面是n
ll get_comb(ll n,ll m) {
    return div_mod(factorial[n],mul_mod(factorial[m],factorial[n-m]));
}
class Solution {
    vector<vector<int>> edge;
    int n;
public:
    int waysToBuildRooms(vector<int>& prevRoom) {
        build_factorial();
        n=prevRoom.size();
        edge=vector<vector<int>>(n);
        for (int i=1;i<n;i++) {
            edge.at(prevRoom.at(i)).push_back(i);
        }
        return dfs(0).first;
    }
    // {方案数plan,节点数cnt}
    pll dfs(int cur) {
        if (edge.at(cur).empty()) {
            return {1,1};
        }
        ll plan=0,cnt=0;
        for (int nxt:edge.at(cur)) {
            auto [subPlan,subCnt]=dfs(nxt);
            if (plan==0 && cnt==0) {
                plan=subPlan;
                cnt=subCnt;
                continue;
            }
            cnt+=subCnt;
            plan=mul_mod(plan,subPlan);
            plan=mul_mod(plan,get_comb(cnt,subCnt));
        }
        return {plan,cnt+1};
    }
};