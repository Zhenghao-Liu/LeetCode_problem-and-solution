//dp[i][j1][j2]表示在第i行，机器人1在j1，机器人2在j2
class Solution {
    vector<int> direction{-1,0,1};
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row=grid.size();
        int column=grid.at(0).size();
        vector<vector<vector<int>>> dp(row,vector<vector<int>>(column,vector<int>(column)));
        dp.at(0).at(0).at(column-1)=grid.at(0).at(0)+grid.at(0).at(column-1);
        for (int i=1;i<row;++i)
            for (int j1=0;j1<column;++j1)
            {
                //小剪枝
                if (j1>i)
                    continue;
                for (int j2=column-1;j2>=0;--j2)
                {
                    //小剪枝
                    if (j2<column-i-1)
                        continue;
                    for (int dir1:direction)
                        for (int dir2:direction)
                        {
                            int last_j1=j1+dir1;
                            int last_j2=j2+dir2;
                            if (last_j1>=0 && last_j1<column && last_j2>=0 && last_j2<column)
                            {
                                //注意同一个两个机器人在一个块的情况
                                if (j1==j2)
                                    dp.at(i).at(j1).at(j2)=max(dp.at(i).at(j1).at(j2),dp.at(i-1).at(last_j1).at(last_j2)+grid.at(i).at(j1));
                                else
                                    dp.at(i).at(j1).at(j2)=max(dp.at(i).at(j1).at(j2),dp.at(i-1).at(last_j1).at(last_j2)+grid.at(i).at(j1)+grid.at(i).at(j2));
                            }
                        }
                }
            }
        int ans=0;
        for (int j1=0;j1<column;++j1)
            for (int j2=0;j2<column;++j2)
                ans=max(ans,dp.at(row-1).at(j1).at(j2));
        return ans;
    }
};
