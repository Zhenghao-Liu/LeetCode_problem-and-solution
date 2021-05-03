typedef long long ll;
typedef pair<ll,ll> pii;
class Solution {
public:
    int magicTower(vector<int>& nums) {
        ll sum=1;
        for (int i:nums) {
            sum+=i;
        }
        if (sum<=0) {
            return -1;
        }
        int sz=nums.size();
        int ans=0;
        ll cur=1;
        priority_queue<ll,vector<ll>,less<ll>> pq;
        sum=0;
        for (int i=0;i<sz;i++) {
            if (nums.at(i)>=0) {
                cur+=nums.at(i);
            } else {
                pq.push(-nums.at(i));
                sum+=-nums.at(i);
            }
            while (cur<=sum) {
                sum-=pq.top();
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};