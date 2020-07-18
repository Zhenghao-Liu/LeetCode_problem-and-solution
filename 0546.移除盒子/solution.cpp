/*
* 补充题目：一次可以移除具有相同颜色的连续盒子，是每次只能移除一个滑窗，而不是一次移除同一种颜色所有地方
* 设dp[l][r][k]
  起始下标l(以0开始)，结束下标r，k表示在下标r后面紧接着有k个元素值和boxes[r]相同，的最大积分和
* 比如[l,l+1,···,r-1,r,值同r，值同r，值同r]
  这里有3个元素和boxes[r]相同，即k==3，那么dp[l][r][3]=dp[l][r-1][0]+4*4
  因为有3个和[r]相同，即可以消除4个所以加上4*4
** 得到初始化条件dp[l][r][k]=dp[l][r-1][0]+(k+1)*(k+1)
* 但是有可能在boxes[l]~boxes[r-1]中也存在和boxes[r]相同值的元素，有可能获得更大的积分和
  比如[l,l+1,···,i,···,r-1,r,值同r，值同r，值同r]，假设boxes[i]==boxes[r]
  那么可能先移除boxes[i+1]~boxes[r-1]，这样就能使原来的dp[l][r][3]的k=3变的更大，但是r变得更小，但是积分和更大
  因此就需要在boxes[l]~boxes[r-1]中找到boxes[i]==boxes[r]
** 这样子先移除boxes[i+1]~boxes[r-1]，这一部分的最大积分和是dp[i+1][r-1][0]
  移除之后是[l,l+1,···,i,值同i(原来是r)，值同i(原来是r+1)，值同i(原来是r+2)，值同i(原来是r+3)]
  剩下这部分是dp[l][i][k+1]
** 总和起来就是dp[l][r][k]=max(dp[l][r][k],dp[i+1][r-1][0]+dp[l][i][k+1])
* 最后的答案就是dp[0][boxes.size()-1][0]
*/
class Solution {
    int dp[100][100][100];
public:
    int removeBoxes(vector<int>& boxes) {
        int size=boxes.size();
        memset(dp,0,sizeof(dp));
        return get_dp(boxes,0,size-1,0);
    }
    int get_dp(vector<int> &boxes,int l,int r,int k)
    {
        if (l>r)
            return 0;
        //记忆化
        if (dp[l][r][k]!=0)
            return dp[l][r][k];
        //尽可能的缩小r可以让递归剪枝
        while (l<r && boxes.at(r)==boxes.at(r-1))
        {
            --r;
            ++k;
        }
        dp[l][r][k]=get_dp(boxes,l,r-1,0)+(k+1)*(k+1);
        for (int i=l;i<r;++i)
            if (boxes.at(i)==boxes.at(r))
                dp[l][r][k]=max(dp[l][r][k],get_dp(boxes,i+1,r-1,0)+get_dp(boxes,l,i,k+1));
        return dp[l][r][k];
    }
};
