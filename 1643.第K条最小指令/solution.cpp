/*
 * 题意就是给定数量个V与H，要求构造出字典序第k个的string
 * 可以把V看成是1，把H看成是0
 * 首先要求出i个0和j个1，能构成多少种string
   两种方法
   1. dp[i][j]等于i个0和j个1能构成string的数量
      dp[i][j]=dp[i-1][j]+dp[i][j-1]可以理解为第一位要么是0要么是1，剩下的排列有多少种
   2. dp[i][i+j]等于一共i+j个数字，求里面放i个0的可能性，可以用排列组合求
 * 构造完后，因为是字典序排第k个的string，
   就先拿首位是0的排列有多少种来比较
 * 即现在需要构造zero个0，one个1
   第一位是0的话则是dp[i-1][j]，
   1. 如果k比dp[i-1][j]要小，则表明第一位是0即H
   2. 如果k比dp[i-1][j]要大，则表明第一位是1即V
 * 如此迭代下去，直到0和1都用完为止
 */
const int MAXN=16;
int cnt[MAXN][MAXN];
class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int one=destination.at(0);//1:V m
        int zero=destination.at(1);//0:H n
        memset(cnt,0,sizeof(cnt));
        for (int j=1;j<=one;++j)
            cnt[0][j]=1;
        for (int i=1;i<=zero;++i)
            cnt[i][0]=1;
        for (int i=1;i<=zero;++i)
            for (int j=1;j<=one;++j)
                cnt[i][j]=cnt[i-1][j]+cnt[i][j-1];
        string ans;
        while (k>0 && zero>0 && one>0)
        {
            if (cnt[zero-1][one]>=k)
            {
                ans+='H';
                --zero;
            }
            else
            {
                ans+='V';
                k-=cnt[zero-1][one];
                --one;
            }
        }
        while (one>0)
        {
            ans+='V';
            --one;
        }
        while (zero>0)
        {
            ans+='H';
            --zero;
        }
        return ans;
    }
};
