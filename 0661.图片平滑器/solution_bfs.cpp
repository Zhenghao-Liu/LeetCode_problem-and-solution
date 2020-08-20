class Solution {
    int dir_x[9]={-1,-1,-1,0,0,0,1,1,1};
    int dir_y[9]={-1,0,1,-1,0,1,-1,0,1};
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> ans=M;
        int row=M.size(),cloumn=M.at(0).size();
        for (int i=0;i<row;++i)
            for (int j=0;j<cloumn;++j)
            {
                int count=0;
                int sum=0;
                for (int k=0;k<9;++k)
                {
                    int x=i+dir_x[k];
                    int y=j+dir_y[k];
                    if (x>=0 && x<row && y>=0 && y<cloumn)
                    {
                        ++count;
                        sum+=M.at(x).at(y);
                    }
                }
                ans.at(i).at(j)=sum/count;
            }
        return ans;
    }
};
