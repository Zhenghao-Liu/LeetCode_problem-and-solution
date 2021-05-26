// 前缀和求任意数数组的和，单调栈求出每个元素比它小的左右最近位置
typedef long long ll;
ll mod=1e9+7;
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int sz=nums.size();
        vector<ll> sum(sz+1);
        for (int i=0;i<sz;i++) {
            sum.at(i+1)=sum.at(i)+nums.at(i);
        }
        vector<int> r(sz,-1),l(sz,-1);
        stack<int> sta;
        sta.push(-1);
        for (int i=sz-1;i>=0;i--) {
            int cur=nums.at(i);
            while (sta.top()!=-1 && nums.at(sta.top())>=cur) {
                sta.pop();
            }
            if (sta.top()!=-1) {
                r.at(i)=sta.top()-1;
            } else {
                r.at(i)=sz-1;
            }
            sta.push(i);
        }
        while (!sta.empty()) {
            sta.pop();
        }
        sta.push(-1);
        for (int i=0;i<sz;i++) {
            int cur=nums.at(i);
            while (sta.top()!=-1 && nums.at(sta.top())>=cur) {
                sta.pop();
            }
            if (sta.top()!=-1) {
                l.at(i)=sta.top()+1;
            } else {
                l.at(i)=0;
            }
            sta.push(i);
        }
        ll ans=0;
        for (int i=0;i<sz;i++) {
            ll a=l.at(i);
            ll b=r.at(i);
            // cout << a << ' ' << b << endl;
            ll cur=nums.at(i);
            ans=max(ans,cur*(sum.at(b+1)-sum.at(a)));
        }
        return ans%mod;
    }
};