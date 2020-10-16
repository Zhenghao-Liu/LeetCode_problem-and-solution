/*
 * 1e6=11110100001001000000，即最多20位，
   即二进制下最多1只可能出现19个，所以统计20以内的质数
 * 即{2,3,5,7,11,13,17,19}
 * __builtin_popcount(x)返回x的二进制中1的个数
 */
unordered_set<int> prime_num{2,3,5,7,11,13,17,19};
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int ans=0;
        for (int i=L;i<=R;++i)
        {
            int cnt=__builtin_popcount(i);
            if (prime_num.find(cnt)!=prime_num.end())
                ++ans;
        }
        return ans;
    }
};
