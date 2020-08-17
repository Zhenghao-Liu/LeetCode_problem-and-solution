/*
1. 如果 n 是素数的话，我们只能通过复制 1 次A，然后粘贴 n - 1 次的方式才能得到 n 个A。总的操作了 n 次。
2. 如果 n = i * j 的话，最快得到 n 的方式是先得到 i ，复制 1 次，然后再粘贴 j - 1 次，总的就有了 n 个A。总的操作了 minSteps(i) + 1 + j - 1 = minSteps(i) + j = minSteps(i) + n / i 次
对于第二步则从2到n-1遍历，这样子保证了先分割出来的因子较小
*/
class Solution {
public:
    int minSteps(int n) {
        if (n==1)
            return 0;
        for (int j=2;j<n;++j)
            if (n%j==0)
                return j+minSteps(n/j);
        return n;
    }
};
