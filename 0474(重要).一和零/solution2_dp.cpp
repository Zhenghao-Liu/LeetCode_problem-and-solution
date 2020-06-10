/**
* 因为只和上一维i-1有关
* 那么可以从三维[i][j][k]压缩到[j][k]即可
* 但这时不能再正着填dp数组了
  因为dp[j][k]=dp[j-zero][k-one]
  倘若正着填对于后面的[j][k]来说[j-zero][k-one]不再是[i-1][j-zero][k-one]因为前面可能已经修改过了
  所以反着填
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int strs_size=strs.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for (string &i:strs)
        {
            pair<int,int> count=count_zero_one(i);
            int zero=count.first;
            int one=count.second;
            for (int j=m;j>=0;--j)
                for (int k=n;k>=0;--k)
                {
                    if (j>=zero && k>=one)
                        dp.at(j).at(k)=max(dp.at(j).at(k),dp.at(j-zero).at(k-one)+1);
                }
        }
        return dp.at(m).at(n);
    }
    pair<int,int> count_zero_one(string &s)
    {
        int zero=0,one=0;
        for (char &i:s)
            if (i=='0')
                ++zero;
            else
                ++one;
        return {zero,one};
    }
};
