map<vector<int>,int> path;
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        path.clear();
        path[vector<int>(needs.size(),0)]=0;
        return dfs(price,special,needs);
    }
    int dfs(vector<int> &price,vector<vector<int>> &special,vector<int> needs)
    {
        auto p=path.find(needs);
        if (p!=path.end())
            return p->second;
        int ans=buy_single(price,needs);
        int size=price.size();
        vector<int> buy_special_needs(size);
        for (vector<int> &i:special)
        {
            int j;
            for (j=0;j<size;++j)
            {
                buy_special_needs.at(j)=needs.at(j)-i.at(j);
                if (buy_special_needs.at(j)<0)
                    break;
            }
            if (j!=size)
                continue;
            ans=min(ans,i.at(size)+dfs(price,special,buy_special_needs));
        }
        path[needs]=ans;
        return ans;
    }
    int buy_single(vector<int> &price,vector<int> &needs)
    {
        int ans=0;
        int size=price.size();
        for (int i=0;i<size;++i)
            ans+=price.at(i)*needs.at(i);
        return ans;
    }
};
