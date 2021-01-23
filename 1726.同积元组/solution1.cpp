/*
 * 1e3数据量，所以可以先n^2的求出所有乘积结果
 * 在出现相同乘积的结果个数组有顺序取出两个，即A_{cnt}^{2}
   每一组等号即4个数字，有4种情况，即2*2种
 * 求和即可
 */
typedef long long ll;
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> ump;
        int size=nums.size();
        for (int i=0;i<size;i++) {
            int a=nums.at(i);
            for (int j=i+1;j<size;j++) {
                int b=nums.at(j);
                ump[a*b]++;
            }
        }
        int ans=0;
        for (auto &i:ump) {
            if (i.second>1) {
                ans+=get_perm(i.second,2)*4;
            }
        }
        return ans;
    }
    ll get_perm(ll n,ll m) {
        ll ans=1;
        for(ll i=n;i>n-m;--i)
        {
            ans*=i;
        }
    return ans;
}
};
