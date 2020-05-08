class Solution {
public:
    bool canCross(vector<int>& stones) {
        int stones_size=stones.size();
        vector<vector<bool>> dp(stones_size,vector<bool>(stones_size,false));
        dp[0][0]=true;
        for (int i=1;i<stones_size;++i)
        {
            int left=0,right=i-1;
            //采用二分来确定起始点
            while (left<right)
            {
                int mid=left+(right-left)/2;
                int try_k=stones[i]-stones[mid];
                if (try_k>stones_size-1)
                    left=mid+1;
                else
                    right=mid;
            }
            for (int j=left;j<i;++j)
            {
                int k=stones[i]-stones[j];
                if (k>stones_size-1)
                    continue;
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
