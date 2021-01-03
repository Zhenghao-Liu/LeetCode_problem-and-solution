/*
* ryr看成ry+r
* 最右边的变成纯r区间的操作步数很好求
  只需从右到左扫一遍看有几个y即可
* dp[i][0]表示[0]~[i]变成全r的序列所需步数
  dp[i][1]表示[0]~[i]变成全y的序列所需步数
  dp[i][2]表示[0]~[i]变成前半是全r的序，后半是全y的序列，即r···ry···y列所需步数
*/
class Solution {
public:
    int minimumOperations(string leaves) {
        int size=leaves.size();
        vector<int> rly(size);
        //从右到左[i~size-1]的y的个数
        rly.at(size-1)=leaves.at(size-1)=='r' ? 0 : 1;
        for (int i=size-2;i>=0;--i)
            rly.at(i)=leaves.at(i)=='r' ? rly.at(i+1) : rly.at(i+1)+1;
        vector<vector<int>> dp(size,vector<int>(3,INT_MAX/2));
        if (leaves.at(0)=='r')
        {
            dp.at(0).at(0)=0;
            dp.at(0).at(1)=1;
        }
        else
        {
            dp.at(0).at(1)=0;
            dp.at(0).at(0)=1;
        }
        for (int i=1;i<size;++i)
        {
            if (leaves.at(i)=='r')
            {
                dp.at(i).at(0)=dp.at(i-1).at(0);
                dp.at(i).at(1)=dp.at(i-1).at(1)+1;
                int t=INT_MAX;
                t=min(t,dp.at(i-1).at(2)+1);
                t=min(t,dp.at(i-1).at(0)+1);
                t=min(t,dp.at(i-1).at(1)+2);
                dp.at(i).at(2)=t;
            }
            //y
            else
            {
                dp.at(i).at(0)=dp.at(i-1).at(0)+1;
                dp.at(i).at(1)=dp.at(i-1).at(1);
                int t=INT_MAX;
                t=min(t,dp.at(i-1).at(0));
                t=min(t,dp.at(i-1).at(2));
                t=min(t,dp.at(i-1).at(1)+1);
                dp.at(i).at(2)=t;
            }
        }
        int ans=INT_MAX;
        for (int i=1;i<size-1;++i)
            ans=min(ans,dp.at(i).at(2)+rly.at(i+1));
        return ans;
    }
};
