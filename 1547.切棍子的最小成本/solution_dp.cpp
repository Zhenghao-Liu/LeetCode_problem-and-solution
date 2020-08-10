/*
* 显然按照长度贪心或者二分都是错误的，类似于1 1 1这种3个相同长度连在一起时无法贪心的选择
* 初始想法是dp[i][j]代表从长度i到长度j完全切割棍子的最小成本
  那么dp[i][j]=min(dp[i][j],dp[i][切割点]+dp[切割点][j]+(j-i))
  但是n的范围是1e6，显然会mle
* 那么通过离散化的方式，将dp[i][j]中的i、j离散化到cuts的索引
  且要离散化即切割点要加入0以及n这两个点到cuts中，并且cuts要排序因为是乱序的
  即排序后cuts[0]=0、cuts.back()=n
* 新dp[i][j]定义为从刻度cuts[i]到刻度cuts[j]完全切割棍子的最小成本
  最终的答案就是dp[0][cuts.size()-1]
* 初始化dp[i][i+1]=0因为这是不可切割的最小分段，代表刻度cuts[i]到cuts[j]的棍子，因为不能切割所以成本为0
* 对于dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+(cust[j]-cuts[i]))
  即从原来的刻度cuts[i]到刻度cuts[j]，切割成两段
  第一段是刻度cuts[i]到刻度cuts[k]
  第二段是刻度cuts[k]到刻度cuts[j]
  且这一次切割成本是cuts[j]-cuts[i]
* 就只剩考虑dp转移的方向，因为dp转移依赖于该行左边所有元素已经该列下面所有元素，且最后填右上角的元素
  采用了从下到上，从左到右的顺序填dp表
*/
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int cuts_size=cuts.size();
        vector<vector<int>> dp(cuts_size,vector<int>(cuts_size,INT_MAX/2));
        for (int i=1;i<cuts_size;++i)
            dp.at(i-1).at(i)=0;
        for (int j=2;j<cuts_size;++j)
            for (int i=j-1;i>=0;--i)
                for (int k=i+1;k<j;++k)
                    dp.at(i).at(j)=min(dp.at(i).at(j),dp.at(i).at(k)+dp.at(k).at(j)+cuts[j]-cuts[i]);
        return dp.at(0).at(cuts_size-1);
    }
};
