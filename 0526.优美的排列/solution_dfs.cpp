//直接回溯求所有可能
bool use[16];
class Solution {
public:
    int countArrangement(int N) {
        memset(use,false,sizeof(use));
        int ans=0;
        dfs(1,N,ans);
        return ans;
    }
    void dfs(int cur,int N,int &ans)
    {
        if (cur>N)
        {
            ++ans;
            return;
        }
        for (int i=1;i<=N;++i)
            if (!use[i] && (cur%i==0 || i%cur==0))
            {
                use[i]=true;
                dfs(cur+1,N,ans);
                use[i]=false;
            }
    }
};
