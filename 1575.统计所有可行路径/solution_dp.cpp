//dp[i][j]表示在第i个城市剩余j汽油量时，到达的路径数量
class Solution {
    int mod=1e9+7;
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int size=locations.size();
        vector<vector<int>> dp(size,vector<int>(fuel+1,0));
        dp.at(start).at(fuel)=1;
        for (int f=fuel;f>=0;--f)
            for (int u=0;u<size;++u)
                for (int v=0;v<size;++v)
                {
                    if (u==v)
                        continue;
                    //u->v 使用汽油abs(locations[u]-locations[v])
                    int cost_f=abs(locations.at(u)-locations.at(v));
                    if (f<cost_f)
                        continue;
                    dp.at(v).at(f-cost_f)+=dp.at(u).at(f);
                    dp.at(v).at(f-cost_f)%=mod;
                }
        int ans=0;
        for (int i=0;i<=fuel;++i)
        {
            ans+=dp.at(finish).at(i);
            ans%=mod;
        }
        return ans;
    }
};
