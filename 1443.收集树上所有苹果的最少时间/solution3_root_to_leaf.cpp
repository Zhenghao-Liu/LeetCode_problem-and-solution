class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> figure(n);
        for (vector<int> &i:edges)
        {
            figure.at(i.at(0)).push_back(i.at(1));
            figure.at(i.at(1)).push_back(i.at(0));
        }
        dfs(figure,hasApple,0,-1);
        int ans=0;
        for (bool i:hasApple)
            if (i)
                ++ans;
        if (ans<=1)
            return ans;
        return (ans-1)*2;
    }
    void dfs(vector<vector<int>> &figure,vector<bool> &hasApple,int start,int last)
    {
        for (int &i:figure.at(start))
        {
            if (i!=last)
            {
                dfs(figure,hasApple,i,start);
                hasApple.at(start)=hasApple.at(start) | hasApple.at(i);
            }
        }
    }
};
