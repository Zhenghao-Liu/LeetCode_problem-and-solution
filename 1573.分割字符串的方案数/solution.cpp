/*
* 既然s1 s2 s3中的1的个数相同
* 所以先统计出s总数1的个数，之后/3即是每个部分1的个数
* 即s1 s2 s3一定要包含count/3个1，所以影响分的方案数的是0的个数
* 找到s1最右边的1与s2最左边的1，中间的0的个数
  与s2最右边的1与s3最左边的1，中间的0的个数
  排列组合即可
* 注意没有1的情况
*/
class Solution {
    int mod=1e9+7;
public:
    int numWays(string s) {
        int count=0;
        int size=s.size();
        for (char i:s)
            if (i=='1')
                ++count;
        if (count==0)
        {
            long long a=size-2;
            long long b=size-2;
            b=b*(b-1)/2;
            b%=mod;
            a+=b;
            a%=mod;
            return a;
        }
        if (count%3!=0)
            return 0;
        vector<int> v;
        int zero=0;
        for (int i=0;i<=size;++i)
        {
            if (i==size || s.at(i)=='1')
            {
                v.push_back(zero);
                zero=0;
            }
            else
                ++zero;
        }
        long long a=v.at(count/3);
        long long b=v.at(count/3*2);
        return (a+1)*(b+1)%mod;
    }
};
