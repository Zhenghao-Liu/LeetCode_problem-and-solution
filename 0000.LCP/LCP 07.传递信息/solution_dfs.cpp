class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        unordered_map<int,vector<int>> mask;
        for (vector<int> &i:relation)
            mask[i.at(0)].push_back(i.at(1));
        int ans=0;
        dfs(0,mask,0,ans,k,n-1);
        return ans;
    }
    void dfs(int index,unordered_map<int,vector<int>>& mask,int step,int &ans,const int &k,int final_p)
    {
        if (step==k)
        {
            if (index==final_p)
                ++ans;
            return;
        }
        if (mask.find(index)==mask.end())
            return;
        for (int &i:mask.at(index))
            dfs(i,mask,step+1,ans,k,final_p);
    }
};
