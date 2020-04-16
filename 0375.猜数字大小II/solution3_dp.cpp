//和2解法一样，填充顺序改变，记住填[i][j]时，其左方和下方的数据都已经填好即可
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for (int left=n-1;left>=1;--left)
            for (int right=left+1;right<=n;++right)
            {
                int ans=INT_MAX;
                for (int i=left+1;i<right;++i)
                    ans=min(ans,i+max(dp.at(left).at(i-1),dp.at(i+1).at(right)));
                ans=min(ans,left+dp.at(left+1).at(right));
                ans=min(ans,right+dp.at(left).at(right-1));
                dp.at(left).at(right)=ans;
            }
        return dp.at(1).at(n);
    }
};
