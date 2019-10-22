class Solution {
public:
bool isMatch(string s, string p)
{
	int s_size=s.size(),p_size=p.size();
	if (p_size==0)
		return s_size==0;
	//需创建一个[s_size+1][p_size+1]大的dp数组，因有s_size=0或p_size=0这种情况发生
	vector<vector<bool>> dp(s_size+1,vector<bool>(p_size+1,false));
	//初始化dp表
	dp.at(0).at(0)=true;
	for (int j=1;j<p_size+1;++j)
		if (p.at(j-1)=='*')
			dp.at(0).at(j)=dp.at(0).at(j-1);
        else
            break;//如果有一个是false，后面全为false，可直接跳出循环
	//开始执行dp
	for (int i=1;i<s_size+1;++i)
		for (int j=1;j<p_size+1;++j)
		{
			if (p.at(j-1)==s.at(i-1) || p.at(j-1)=='?')
				dp.at(i).at(j)=dp.at(i-1).at(j-1);
			if (p.at(j-1)=='*')
				dp.at(i).at(j)=dp.at(i).at(j-1)|| dp.at(i-1).at(j);//*匹配零个、有限个字符
		}
	return dp.at(s_size).at(p_size);
}
};
