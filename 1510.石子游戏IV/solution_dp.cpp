//设dp[i]为先手时剩下i个石头，是否必胜
//因为每次只能取平方数个，测dp[i]=!dp[i-平方数]，别人的失败就是我的胜利
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1);
        dp.at(0)=false;
        for (int i=1;i<=n;++i)
        {
            for (int j=sqrt(i);j>=1;--j)
            {
                dp.at(i)=!dp.at(i-j*j);
                if (dp.at(i))
                    break;
            }
        }
        return dp.at(n);
    }
};
