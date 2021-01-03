// 最大数是2^20，即和之后的最大幂次是2^21，所以可以O(21*n)的用twosum去枚举
typedef long long ll;
const int UP=21;
class Solution {
    ll mod=1e9+7;
public:
    int countPairs(vector<int>& d) {
        unordered_map<int,int> ump;
        ll ans=0;
        for (int i:d) {
            for (int j=UP;j>=0;j--) {
                int sum=1<<j;
                int tar=sum-i;
                if (ump.find(tar)!=ump.end()) {
                    ans+=ump.at(tar);
                    ans%=mod;
                }
            }
            ump[i]++;
        }    
        return ans;
    }
};
