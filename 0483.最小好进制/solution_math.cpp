/*
* 设n表示为s+1位数，进制为k
* 对于所有s>=2 k<n^(1/s)<k+1
* 且最小2进制时，对于n<10^18，即s最大可以取59
* 就枚举s，然后根据不等式就k，然后判断是否是全1
*/
class Solution {
public:
    string smallestGoodBase(string n) {
        long long num=stoll(n);
        long long ans=num-1;
        for (int s=59;s>=2;--s)
        {
            long long k=pow(num,(1.0/s));
            if (k>1)
            {
                long long sum=1;
                long long single=1;
                for (int i=1;i<=s;++i)
                {
                    single*=k;
                    sum+=single;
                }
                if (sum==num)
                {
                    ans=k;
                    break;
                }
            }
        }
        return to_string(ans);
    }
};
