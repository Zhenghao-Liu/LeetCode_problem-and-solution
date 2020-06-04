/**
* 对于0~k-1
  dp[i]=(dp[i+1]+dp[i+2]+···dp[i+W])/W
* 那么(dp[i+1]=dp[i+2]+dp[i+3]+···dp[i+1+W])/W
  那么dp[i]-dp[i+1]=(dp[i+1]-dp[i+1+W])/W
** 则新的转移方程
  dp[i]=dp[i+1]+(dp[i+1]-dp[i+1+W])/W 0<=i<k-1
* 但是对于k-1这个最大可再抽一张牌数不适用
  因为dp[K-1+1]即dp[K]是必胜的情况即概率为1
* 所以dp[K-1]用老动态方程来做dp[i]=(dp[i+1]+dp[i+2]+···dp[i+W])/W
  又因为在K~min(K-1+W,N)是必胜的
  即必胜有min(K-1+W,N)-K+1种情况是必胜的即概率为1，即分子是min(K-1+W,N)-K+1
  分母是W
*/
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K==0)
            return 1.0;
        vector<double> dp(K+W,0);
        int upper_win=min(K-1+W,N);
        for (int i=K;i<=upper_win;++i)
            dp.at(i)=1.0;
        dp.at(K-1)=1.0*(upper_win-K+1)/W;
        for (int i=K-2;i>=0;--i)
            dp.at(i)=dp.at(i+1)+(dp.at(i+1)-dp.at(i+1+W))/W;
        return dp.at(0);
    }
};
