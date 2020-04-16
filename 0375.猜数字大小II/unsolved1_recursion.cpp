/*
* 对于(1,n)的数字我们可以第一个猜i，i属于[1,n]
* 假设我们猜了i，如果就是i那我们不花钱
  假如正确答案比i大，则还要在(i+1,n)中猜，且要给i钱
  假如正确答案比i小，则还要在(1,i-1)中猜，且要给i钱
  为了确保至少用多少钱能猜出答案，要在这三种中选取最大值
  同时尽可能少的钱，因此在所有i中取最小的结果
* 因此通用公式对于(left,right)表示从left到right中猜正确答案最少需要花多少钱
  i属于left~right， ans=min(ans,i+max(helper(left,i-1),helper(i+1,right))
  注意边界，当left==right时表明只剩一个数字，那么不用猜都知道这个数字即为0
  当left>right时表明不存在此情况，因为是比较取max，因此返回一个较小值即可，这里最少就是0
*/
class Solution {
public:
    int getMoneyAmount(int n) {
        return helper(1,n);
    }
    int helper(int left,int right)
    {
        if (left>=right)
            return 0;
        int ans=INT_MAX;
        for (int i=left;i<=right;++i)
        {
            int temp=i+max(helper(left,i-1),helper(i+1,right));
            ans=min(ans,temp);
        }
        return ans;
    }
};
