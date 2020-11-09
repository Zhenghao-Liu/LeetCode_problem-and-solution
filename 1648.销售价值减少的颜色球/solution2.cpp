/*
 * 拿了价值x的球，剩下还有x-1个球
 * 先按降序排序后，可以画出一个高度下降的柱状图
 * 即以[i]-[i+1]作为高度h，变成求矩形面积的问题
 * 即每次切割到下界，之后++i其实就是增加宽w
 * 为了分析方便需要额外加一个0进入数组中，这样边界好写一点
 * 等差数列求和公式 n*(a1+an)/2
 */
typedef long long ll;
class Solution {
    int mod=1e9+7;
public:
    int maxProfit(vector<int>& inventory, int orders) {
        inventory.push_back(0);
        sort(inventory.rbegin(),inventory.rend());
        ll ans=0;
        int size=inventory.size();
        for (int i=0;i<size-1 && orders>0;++i)
        {
            int w=i+1;
            int h=inventory.at(i)-inventory.at(i+1);
            int all=w*h;
            if (orders>=all)
            {
                ll a1=inventory.at(i),an=inventory.at(i+1)+1,n=h;
                ans+=(long long)w*n*(a1+an)/2%mod;
                ans%=mod;
            }
            //else if (orders<all)
            else
            {
                int all_w_h=orders/w;
                ll a1=inventory.at(i),an=inventory.at(i)-all_w_h+1;
                ans+=(long long)w*all_w_h*(a1+an)/2%mod;
                ans%=mod;
                int rest_ball=orders%w;
                ans+=(long long)rest_ball*(an-1)%mod;
                ans%=mod;
            }
            orders-=all;
        }
        return ans;
    }
};
