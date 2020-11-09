/*
 * 拿了价值x的球，剩下还有x-1个球
 * 二分枚举下界：一定能满足orders的最下界
 * 但是有可能会过满足，所以还需要减去过满足的球数
 * 等差数列求和公式 n*(a1+an)/2
 */
typedef long long ll;
class Solution {
    int mod=1e9+7;
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int l=0,r=*max_element(inventory.begin(),inventory.end());
        while (l<r)
        {
            int mid=l+(r-l+1)/2;
            if (check(inventory,mid,orders))
                l=mid;
            else
                r=mid-1;
        }
        ll ans=0;
        for (int i:inventory)
            if (i>l)
            {
                ll a1=i,an=l+1,n=a1-an+1;
                ans+=(a1+an)*n/2%mod;
                ans%=mod;
                orders-=n;
            }
        orders=-orders;
        ans=(ans-(ll)orders*(l+1)%mod+mod)%mod;
        return ans;
    }
    bool check(vector<int> & inventory,int lower,int orders)
    {
        int sum=0;
        for (int i:inventory)
        {
            sum+=max(0,i-lower);
            if (sum>=orders)
                return true;
        }
        return false;
    }
};
