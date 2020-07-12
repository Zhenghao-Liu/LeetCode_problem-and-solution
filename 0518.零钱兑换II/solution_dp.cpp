class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int coins_size=coins.size();
        vector<int> dp(amount+1);
        dp.at(0)=1;
        //for (int i=1;i<=n;++i)
        //    dp.at(i)=0;
        //dp[i][j]表i种硬币构成总值j的方法数
        //倘若不拿第i个硬币dp[i][j]=dp[i-1][j]
        //倘若拿第i个硬币dp[i][j]=dp[i][j-第i个硬币的面值]
        //只与上一行和左边有关，可以压缩成一行
        for (int &i:coins)
            for (int j=1;j<=amount;++j)
                if (j>=i)
                    dp.at(j)+=dp.at(j-i);
        return dp.at(amount);
    }
};
