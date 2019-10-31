/*
* 当 j>i && t.at(i)==s.at(j) 情况下dp.at(i).at(j)=dp.at(i).at(j-1)+dp.at(i-1).at(j-1);
* 可以这样子理解
* 假设s="aaa"，t="aa"
* 当 i=1 j=2时即都是对应着最后一个字母
* 刚好满足上面的情况
* 1. dp.at(i-1).at(j-1) 意味着t的最后一个字符一定是匹配s的最后一个字符，即找子序列时，对于t.at(1)他一定是匹配s.at(2)，那么这时候只需要找s和t都去掉最后一个字符后，子序列匹配的个数就可以了，这里结果是2
* 2. dp.at(i).at(j-1) 意味着t的最后一个字符一定不是对应s的最后一个字符，因为在s中可能有重复个字符和t.at(i)相同，那么只需要s删除最后一个字符后再与t来匹配子序列即可
*/
class Solution {
public:
int numDistinct(string s, string t) 
{
    int s_size=s.size(),t_size=t.size();
	if (s_size<t_size)
		return 0;
	else if (s_size==t_size)
	{
		if (s==t)
			return 1;
		else
			return 0;
	}	
	else if (t_size==0)
		return 1;
	vector<vector<double>> dp(t_size,vector<double>(s_size,0));
	if (s.at(0)==t.at(0))
		dp.at(0).at(0)=1;
	else
		dp.at(0).at(0)=0;
	for (int i=1;i<s_size;++i)
		if (t.at(0)==s.at(i))
			dp.at(0).at(i)=dp.at(0).at(i-1)+1;
		else
			dp.at(0).at(i)=dp.at(0).at(i-1);
	for (int i=1;i<t_size;++i)
		for (int j=i;j<s_size;++j)
			if (j>i)
			{
				if (t.at(i)==s.at(j))
					dp.at(i).at(j)=dp.at(i).at(j-1)+dp.at(i-1).at(j-1);
				else
					dp.at(i).at(j)=dp.at(i).at(j-1);
			}
			else
			{
				if (t.at(i)==s.at(j))
					dp.at(i).at(j)=dp.at(i-1).at(j-1);
				else
					dp.at(i).at(j)=0;
			}
	return dp.at(t_size-1).at(s_size-1);
}
};
