//dp[i]表示长度为[0,i]所需片段的最小数目
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int size=clips.size();
        vector<int> dp(T+1,INT_MAX/2);
        for (int i=0;i<=T;++i)
        {
            for (int j=0;j<size;++j)
            {
                int x=clips.at(j).at(0);
                int y=clips.at(j).at(1);
                if (y>=i)
                {
                    if (x==0)
                        dp.at(i)=1;
                    else if (x<=i)
                        dp.at(i)=min(dp.at(i),dp.at(x)+1);
                }
            }
        }
        return dp.at(T)==INT_MAX/2 ? -1 : dp.at(T);
    }
};
