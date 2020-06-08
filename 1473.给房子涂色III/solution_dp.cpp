class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n+1,vector<int>(target+1,INT_MAX)));
        if (houses.at(0)!=0)
        {
            dp.at(0).at(houses.at(0)).at(1)=0;
        }
        //else if (houses.at(0)==0)
        else
        {
            for (int j=0;j<n;++j)
            {
                dp.at(0).at(j+1).at(1)=cost.at(0).at(j);
            }
        }
        for (int i=1;i<m;++i)
        {
            if (houses.at(i)!=0)
            {
                for (int j=1;j<n+1;++j)
                {
                    for (int k=1;k<target+1;++k)
                        if (dp.at(i-1).at(j).at(k)!=INT_MAX)
                        {
                            if (houses.at(i)==j)
                                dp.at(i).at(houses.at(i)).at(k)=min(dp.at(i).at(houses.at(i)).at(k),dp.at(i-1).at(j).at(k));
                            else if (k!=target)
                                dp.at(i).at(houses.at(i)).at(k+1)=min(dp.at(i).at(houses.at(i)).at(k+1),dp.at(i-1).at(j).at(k));
                        }
                }
            }
            //else if (houses.at(i)==0)
            else
            {
                for(int j=1;j<n+1;++j)
                {
                    for (int k=1;k<target+1;++k)
                        if (dp.at(i-1).at(j).at(k)!=INT_MAX)
                        {
                            for (int jj=1;jj<n+1;++jj)
                            {
                                if (jj==j)
                                    dp.at(i).at(jj).at(k)=min(dp.at(i).at(jj).at(k),dp.at(i-1).at(j).at(k)+cost.at(i).at(jj-1));
                                else if (k!=target)
                                    dp.at(i).at(jj).at(k+1)=min(dp.at(i).at(jj).at(k+1),dp.at(i-1).at(j).at(k)+cost.at(i).at(jj-1));
                            }
                        }
                }
            }
        }
        int ans=INT_MAX;
        for (int j=1;j<n+1;++j)
            if (dp.at(m-1).at(j).at(target)!=INT_MAX)
                ans=min(ans,dp.at(m-1).at(j).at(target));
        return ans==INT_MAX ? -1 : ans;
    }
};
