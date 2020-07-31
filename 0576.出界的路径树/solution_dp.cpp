/*
* 现在原先m*n矩阵上加一圈外围，即变成m+2*n+2
* dp[i][j][k]:表示从(i,j)出发第k步出界的路径总数，等价于从外界出发第k步走到(i,j)的路径总数
* 显然对于最外围一圈本身就是在界外，dp[边界i][边界j][0]=1自然一步不用走就出界了
* dp[i][j][k]=dp[i-1][j][k-1]+dp[i][j-1][k-1]+dp[i+1][j][k-1]+dp[i][j+1][k-1]
*/
class Solution {
    vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    int mod=1e9+7;
public:
    int findPaths(int m, int n, int N, int start_i, int start_j) {
        vector<vector<vector<int>>> dp(m+2,vector<vector<int>>(n+2,vector<int>(N+1)));
        for (int i=0;i<=m+1;++i)
        {
            dp.at(i).at(0).at(0)=1;
            dp.at(i).at(n+1).at(0)=1;
        }
        for (int j=0;j<=n+1;++j)
        {
            dp.at(0).at(j).at(0)=1;
            dp.at(m+1).at(j).at(0)=1;
        }
        for (int k=1;k<=N;++k)
            for (int i=1;i<=m;++i)
                for (int j=1;j<=n;++j)
                {
                    int x,y;
                    for (pair<int,int> &p:dir)
                    {
                        x=i+p.first;
                        y=j+p.second;
                        dp.at(i).at(j).at(k)+=dp.at(x).at(y).at(k-1);
                        dp.at(i).at(j).at(k)%=mod;
                    }
                }
        int ans=0;
        for (int k=1;k<=N;++k)
        {
            ans+=dp.at(start_i+1).at(start_j+1).at(k);
            ans%=mod;
        }
        return ans;
    }
};
