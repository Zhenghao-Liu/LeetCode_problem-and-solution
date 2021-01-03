/*
 * 先排序后twosum
 * 因为a+b等于2次幂，设当前是a，没有办法判断在等式中他是较大的还是较小的，所以排序后设当前遍历到的是较大值
   即按升序排序
 * twosum的target值
 * 往二进制去考虑，设当前数字是在二进制下1xxx，那么此时twosum中存哈希表元素一定是比它小的，所以他的2次幂和是比当前要大一位
   即eg：当下二进制下1001，那么它的二进制幂和一定是10000，比原来的要左移一位，并把剩下的取0
 * 特殊情况：当前数字本身就是二进制幂，即10···0，除了2次幂的和是比当前大一位外（和自身相加），还有一种情况就是和0相加
   即2次幂+0=2次幂
 * 特殊情况0：因为哈希表存的都是小于等于当前的元素，所以遍历到0时，暂时构成不了2次幂，
   因为判断2次幂(key&(key-1))==0倘若key==0时也会走true，所以特判
 */
class Solution {
    long long mod=1e9+7;
public:
    int countPairs(vector<int>& d) {
        sort(d.begin(),d.end());
        map<int,int> mp;
        long long ans=0;
        for (int i:d) {
            if (i==0) {
                mp[0]++;
                continue;
            }
            int key=i;
            int cnt=0;
            int mask=key;
            while (mask!=0) {
                mask>>=1;
                cnt++;
            }
            int tar=(1<<cnt)-key;
            auto p=mp.find(tar);
            if (p!=mp.end()) {
                ans+=(long long)((*p).second);
                ans%=mod;
            }
            if ((key&(key-1))==0) {
                if (mp.find(0)!=mp.end()) {
                    ans+=mp.at(0);
                    ans%=mod;
                }
            }
            mp[i]++;
        }
        return ans;
    }
};
