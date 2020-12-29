class Solution {
    int row,col;
    vector<vector<int>> dp;
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid.at(0).size();
        dp=vector<vector<int>>(row,vector<int>(col,INT_MIN));
        vector<int> ans(col,-1);
        for (int j=0;j<col;j++) {
            ans.at(j)=dfs(grid,0,j);
        }
        return ans;
    }
    int dfs(vector<vector<int>> & grid,int x,int y) {
        if (x==row) {
            return y;
        }
        if (dp.at(x).at(y)!=INT_MIN) {
            return dp.at(x).at(y);
        }
        if (grid.at(x).at(y)==1) {
            if (y+1<col && grid.at(x).at(y+1)==1) {
                dp.at(x).at(y)=dfs(grid,x+1,y+1);
            } else {
                dp.at(x).at(y)=-1;
            }
        } else {
            if (y-1>=0 && grid.at(x).at(y-1)==-1) {
                dp.at(x).at(y)=dfs(grid,x+1,y-1);
            } else {
                dp.at(x).at(y)=-1;
            }
        }
        return dp.at(x).at(y);
    }
};
