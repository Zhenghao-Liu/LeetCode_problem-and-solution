//n^4的做法，tle的边缘试探，dp[i][j]表示以[i][j]为右下角的矩形有多少个，暴力枚举高，然后遍历长
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int row=mat.size();
        int column=mat.at(0).size();
        vector<vector<int>> dp(row,vector<int>(column,0));
        int ans=0;
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (mat.at(i).at(j)==1)
                {
                    int min_width=INT_MAX;
                    int k=i;
                    while (k>=0 && mat.at(k).at(j)==1)
                    {
                        int jj=j;
                        while (jj>=0 && mat.at(k).at(jj)==1)
                            --jj;
                        min_width=min(min_width,j-jj);
                        dp.at(i).at(j)+=min_width;
                        --k;
                    }
                    ans+=dp.at(i).at(j);
                }
        return ans;
    }
};
