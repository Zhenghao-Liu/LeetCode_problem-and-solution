//记忆化dfs，因为没有走完所以速度快很多
const int MAXN=501;
int dp[MAXN][MAXN];
int prefix[MAXN];
class Solution {
public:
    int stoneGameV(vector<int>& sV) {
        int n=sV.size();
        prefix[0]=0;
        int sum=0;
        //[i,j]=prefix[j+1]-prefix[i]
        for (int i=0;i<n;++i)
            prefix[i+1]=prefix[i]+sV[i];
        memset(dp,0,sizeof(dp));
        for (int i=1;i<n;++i)
            dp[i-1][i]=min(sV[i-1],sV[i]);
        return dfs(0,n-1);
    }
    int dfs(int start,int end)
    {
        if (start>end)
            return 0;
        if (start==end)
            return 0;
        if (dp[start][end]!=0)
            return dp[start][end];
        for (int k=start;k<end;++k)
        {
            int p1=prefix[k+1]-prefix[start];
            int p2=prefix[end+1]-prefix[k+1];
            int t;
            if (p1>p2)
                t=p2+dfs(k+1,end);
            else if (p1<p2)
                t=p1+dfs(start,k);
            else
                t=max(p1+dfs(start,k),p2+dfs(k+1,end));
            dp[start][end]=max(dp[start][end],t);
        }
        return dp[start][end];
    }
};
