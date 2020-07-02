//dp[i][j]表示公共子数组以A[i]、B[j]结尾(即这个公共子数组末尾是A[i]即B[j])的最长长度
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int A_size=A.size();
        int B_size=B.size();
        vector<vector<int>> dp(A_size+1,vector<int>(B_size+1,0));
        int ans=0;
        for (int i=0;i<A_size;++i)
            for (int j=0;j<B_size;++j)
                if (A.at(i)==B.at(j))
                {
                    dp.at(i+1).at(j+1)=dp.at(i).at(j)+1;
                    ans=max(ans,dp.at(i+1).at(j+1));
                }
        return ans;
    }
};
