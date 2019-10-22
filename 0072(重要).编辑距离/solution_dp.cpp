/*
* 对于边界来说
* dp[0][0]=0
* 第一行即i=0即word1为""的情况，word1变为word2只有插入的操作
* 第一列即j=0即word2为""的情况，word1变为word2只有删除的操作
* 然后对于剩下的i,j
* 如果字母相同则dp[i][j]=dp[i-1][j-1]
* 如果不同则需要考虑插入删除替换3种操作
* 插入dp[i][j]=dp[i][j-1]+1 ,eg:"a","ab"
* 删除dp[i][j]=dp[i-1][j]+1 ,eg:"ab","a"
* 替换dp[i][j]=dp[i-1][j-1]+1 ,eg:"ac","ab"
*/
class Solution {
public:
int minDistance(string word1, string word2)
{
    int word1_size=word1.size(),word2_size=word2.size();
    if (word1_size==0)
        return word2_size;
    else if (word2_size==0)
        return word1_size;
    else if (word1==word2)
        return 0;
	vector<vector<int>> dp(word1_size+1,vector<int>(word2_size+1));
	dp.at(0).at(0)=0;
	for (int i=1;i<=word2_size;++i)
		dp.at(0).at(i)=i;
	for (int i=1;i<=word1_size;++i)
		dp.at(i).at(0)=i;
	for (int i=1;i<=word1_size;++i)
		for (int j=1;j<=word2_size;++j)
			if (word1.at(i-1)==word2.at(j-1))
				dp.at(i).at(j)=dp.at(i-1).at(j-1);
			else
				dp.at(i).at(j)=min(dp.at(i).at(j-1),min(dp.at(i-1).at(j),dp.at(i-1).at(j-1)))+1;
	return dp.at(word1_size).at(word2_size);
}
};
