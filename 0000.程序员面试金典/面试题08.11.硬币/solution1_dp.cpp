class Solution {
    int base=1e9+7;
    vector<int> mask{1,5,10,25};
public:
    int waysToChange(int n) {
        int mask_size=mask.size();
        vector<vector<int>> dp(mask_size+1,vector<int>(n+1));
        dp.at(0).at(0)=1;
        //for (int i=1;i<=n;++i)
        //    dp.at(0).at(i)=0;
        for (int i=1;i<=mask_size;++i)
            dp.at(i).at(0)=1;
        //dp[i][j]表i种硬币构成总值j的方法数
        //倘若不拿第i个硬币dp[i][j]=dp[i-1][j]
        //倘若拿第i个硬币dp[i][j]=dp[i][j-第i个硬币的面值]
        for (int i=1;i<=mask_size;++i)
            for (int j=1;j<=n;++j)
            {
                if (j>=mask.at(i-1))
                    dp.at(i).at(j)=(dp.at(i).at(j-mask.at(i-1))%base+dp.at(i-1).at(j)%base)%base;
                else
                    dp.at(i).at(j)=dp.at(i-1).at(j)%base;
            }
        return dp.at(mask_size).at(n);
    }
};
