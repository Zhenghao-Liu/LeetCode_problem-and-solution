class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int size=M.size();
        vector<bool> visit(size,false);
        int ans=0;
        for (int i=0;i<size;++i)
            if (!visit.at(i))
            {
                visit.at(i)=true;
                ++ans;
                dfs(M,visit,size,i);
            }
        return ans;
    }
    void dfs(vector<vector<int>>& M,vector<bool> & visit,int size,int i)
    {
        for (int j=0;j<size;++j)
            if (!visit.at(j) && M.at(i).at(j)==1)
            {
                visit.at(j)=true;
                dfs(M,visit,size,j);
            }    
    }
};
