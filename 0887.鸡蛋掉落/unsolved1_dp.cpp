/*
* 详情进入[李永乐之双蛋问题讲解](https://www.bilibili.com/video/BV1KE41137PK/)
* dp[i][j]表示检验i层有j个鸡蛋最少移动次数是多少
* 对于只有1个鸡蛋，要想检验出F，多少层就要移动多少次
* 对于第一层，无论多少个鸡蛋，都只需要移动一次
* 对于第a层，扔了一个鸡蛋，没碎，则代表F在a层的上方，即还有i-a层，且还有j个鸡蛋
                         碎了，则代表F在a层的下方，即还有a-1层，碎了一个蛋，还有j-1个
  此外移动带第a层就是移动次数增1了，所以+1
* 要想确保一定能找出F，就是去最大值max(dp[a-1][j-1],dp[i-a][j]
* 要想求最少的移动次数，就是a所有取值中最小一个，所以是min([i][j],max([a-1][j-1],[i-a][j]))
*/
class Solution {
public:
    int superEggDrop(int K, int N) {
        int ** dp=new int * [N+1];
        for (int i=0;i<=N;++i)
            dp[i]=new int[K+1];
        for (int i=1;i<=K;++i)
            dp[1][i]=1;
        for (int i=2;i<=N;++i)
            dp[i][1]=i;
        for (int i=2;i<=N;++i)
            for (int j=2;j<=K;++j)
            {
                dp[i][j]=INT_MAX;
                for (int a=1;a<=i;++a)
                    dp[i][j]=min(dp[i][j],1+max(dp[a-1][j-1],dp[i-a][j]));
            }
        return dp[N][K];
    }
};
