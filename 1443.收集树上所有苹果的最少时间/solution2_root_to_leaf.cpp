class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> figure(n);
        for (vector<int> &i:edges)
        {
            figure.at(i.at(0)).push_back(i.at(1));
            figure.at(i.at(1)).push_back(i.at(0));
        }
        dfs_become_apples(figure,hasApple,0,-1);
        int ans=0;
        dfs(figure,hasApple,0,-1,ans);
        return ans*2;
    }
    void dfs_become_apples(vector<vector<int>> &figure,vector<bool> &hasApple,int start,int 
last)
    {
        for (int &i:figure.at(start))
        {
            if (i!=last)
            {
                dfs_become_apples(figure,hasApple,i,start);
                hasApple.at(start)=hasApple.at(start) | hasApple.at(i);
            }
        }
    }
    void dfs(vector<vector<int>> &figure,vector<bool> &hasApple,int start,int last,int &ans)
    {
        for (int &i:figure.at(start))
        {
            if (i!=last && hasApple.at(i))
            {
                ++ans;
                dfs(figure,hasApple,i,start,ans);
            }
        }
    }
};
