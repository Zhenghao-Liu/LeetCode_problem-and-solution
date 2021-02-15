/*
 * 1 <= k * events.length <= 10^6数据范围，大致在nlogn应该是ok的，且k*n复杂度应该也是ok的
 * 先贪心的排序，让结尾早的排在前面
 * dp[i][j]表示参加k+1个会议考虑到events[i]的时候获得的最大价值
 * 转移有三种可能
   1. 左：直接无视events[i]，即dp.at(i).at(j-1)
   2. 上：少参加一次会议，dp.at(i-1).at(j)
   3. 左上：参加events[i]，但是怎么找到少参加一次会议（当前机会已经给events[i]）的前一次考虑情况呢
 * 因为结尾之前是排序过的，所以可以二分的去查找
 */
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end(),[](const vector<int> &A,const vector<int> &B){
            return A.at(1)==B.at(1) ? A.at(0)<B.at(0) : A.at(1)<B.at(1);
        });
        int sz=events.size();
        vector<vector<int>> dp(k,vector<int>(sz,0));
        vector<int> cho(sz,-1);
        for (int i=1;i<sz;i++) {
            int l=0,r=i-1;
            int cur=events.at(i).at(0);
            while (l<r) {
                int mid=l+(r-l+1)/2;
                int val=events.at(mid).at(1);
                if (val<cur) {
                    l=mid;
                } else {
                    r=mid-1;
                }
            }
            if (l<0 || l>=i || events.at(l).at(1)>=cur) {
                continue;
            }
            cho.at(i)=l;
        }
        dp.at(0).at(0)=events.at(0).at(2);
        for (int j=1;j<sz;j++) {
            dp.at(0).at(j)=max(events.at(j).at(2),dp.at(0).at(j-1));
        }
        for (int i=1;i<k;i++) {
            for (int j=0;j<sz;j++) {
                int cur=events.at(j).at(2);
                if (cho.at(j)!=-1) {
                    cur+=dp.at(i-1).at(cho.at(j));
                }
                dp.at(i).at(j)=max(dp.at(i-1).at(j),cur);
                if (j!=0) {
                    dp.at(i).at(j)=max(dp.at(i).at(j),dp.at(i).at(j-1));
                }
            }
        }
        return dp.at(k-1).at(sz-1);
    }
};
