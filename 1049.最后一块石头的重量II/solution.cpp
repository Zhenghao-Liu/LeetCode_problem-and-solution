/*
 * 可以把选择石头看成放到两个部分，一个正数部分，一个负数部分
   eg：a、b两个石头，设a<b，则剩下的价值是b-a，等于把b放进正数部分，a放进负数部分
 * 那么对于这个新的石头b-a后续该怎么处理呢，
   后面如果是它大，它就是b-a，也就是原来等于把b放进正数部分，a放进负数部分
   后面如果是它小，它就是-(b-a)，也就是a和b对调一下堆，实际也没有产生新的石头
 * 所以题目转化成，给每个元素加上+或-，使得最后的和最小
 * 也就是说正数部分要尽可能等于负数部分，
   也就是尽可能均分两个部分，也就是尽可能选择元素，使得部分和最接近于数组和的一半
 * 转化成背包问题，选择数组和数字，尽可能接近数组和的一半
 * 求出一部分，数组和一减就是另一部分的和，两个部分的绝对值就是最后最小值
 */
const int MAXN=1e3;
const int MAXS=30*100+1;
int dp[MAXN][MAXS];
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sz=stones.size();
        int sum=accumulate(stones.begin(),stones.end(),0);
        memset(dp,0,sizeof(dp));
        for (int i=0;i<sz;i++) {
            for (int j=1;j<=sum/2;j++) {
                dp[i][j]=i>0 ? dp[i-1][j] : 0;
                if (j>=stones.at(i)) {
                    dp[i][j]=max(
                        dp[i][j],
                        i>0 ? dp[i-1][j-stones.at(i)]+stones.at(i) : stones.at(i)
                    );
                }
            }
        }
        int a=dp[sz-1][sum/2],b=sum-a;
        return abs(a-b);
    }
};