class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> figure(n);
        for (vector<int> &i:edges)
        {
            figure.at(i.at(0)).push_back(i.at(1));
            figure.at(i.at(1)).push_back(i.at(0));
        }
        vector<int> father(n);
        get_father(figure,father,0,-1);
        int ans=0;
        vector<bool> visited(n,false);
        for (int i=0;i<n;++i)
        {
            if (hasApple.at(i) && !visited.at(i))
            {
                int node=i;
                if (i==0)
                    continue;
                do
                {
                    visited.at(node)=true;
                    node=father.at(node);
                    ++ans;
                }while(node!=0 && !visited.at(node));
            }
        }
        return ans*2;
    }
    void get_father(vector<vector<int>> &figure,vector<int> &father,int start,int last)
    {
        father.at(start)=last;
        for (int &i:figure.at(start))
            if (i!=last)
                get_father(figure,father,i,start);
    }
};
