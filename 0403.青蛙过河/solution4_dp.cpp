class Solution {
public:
    bool canCross(vector<int>& stones) {
        int stones_size=stones.size();
        vector<vector<bool>> dp(stones_size,vector<bool>(stones_size,false));
        dp[0][0]=true;
        for (int i=1;i<stones_size;++i)
        {
            //从后往前
            for (int j=i-1;j>=0;--j)
            {
                int k=stones[i]-stones[j];
                if (!(k<=stones_size-1))
                    break;
                dp[i][k]=dp[j][k-1] || dp[j][k];
                if (k+1<stones_size)
                    dp[i][k]=dp[i][k] || dp[j][k+1];
                if (i==stones_size-1 && dp[i][k])
                    return true;
            }
        }
        return false;
    }
};
