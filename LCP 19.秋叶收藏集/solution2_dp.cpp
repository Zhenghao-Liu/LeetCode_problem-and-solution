/*
* 直接一点，直接dp描述ryr的三种状态
* dp[i][0]表示[0]~[i]变成全r的序列所需步数
  dp[i][1]表示[0]~[i]变成前半是全r的序，后半是全y的序列，即r···ry···y列所需步数（即字符串长度至少要2）
  dp[i][1]表示[0]~[i]变成前半是全r的序，中间是全y的序列，后面是全r的序列即r···ry···yr···r列所需步数（即字符串长度至少要3）
* 但是状态转移容易遗漏，要多写几个例子考虑完全
*/
class Solution {
public:
    int minimumOperations(string leaves) {
        int size=leaves.size();
        vector<vector<int>> dp(size,vector<int>(3,INT_MAX/2));
        dp.at(0).at(0)= leaves.at(0)=='r' ? 0 : 1;
        for (int i=1;i<size;++i)
        {
            char c=leaves.at(i);
            dp.at(i).at(0)=dp.at(i-1).at(0)+(c=='r' ? 0 : 1);
            dp.at(i).at(1)=dp.at(i-1).at(0)+(c=='y' ? 0 : 1);
            //i-1>=1
            if (i>1)
            {
                dp.at(i).at(1)=min(dp.at(i).at(1),dp.at(i-1).at(1)+(c=='y'? 0 : 1));
                dp.at(i).at(2)=dp.at(i-1).at(1)+(c=='r' ? 0 : 1);
            }
            //i-1>=2
            if (i>2)
                dp.at(i).at(2)=min(dp.at(i).at(2),dp.at(i-1).at(2)+(c=='r' ? 0 : 1));
        }
        return dp.at(size-1).at(2);
    }
};
