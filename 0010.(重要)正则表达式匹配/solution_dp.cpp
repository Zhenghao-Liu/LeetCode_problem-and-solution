class Solution {
public:
bool isMatch(string s, string p)
{
	int s_size=s.size(),p_size=p.size();
	//dp表包括了s_size=0或p_size=0情况，可以省略，但留着可以提速
	if (p_size==0)
		return s_size==0;
	//需创建一个[s_size+1][p_size+1]大的dp数组，因有s_size=0或p_size=0这种情况发生
	vector<vector<bool>> dp(s_size+1,vector<bool>(p_size+1,false));
	//初始化dp表
	dp.at(0).at(0)=true;
	for (int j=2;j<p_size+1;++j)
		if (p.at(j-1)=='*')
			dp.at(0).at(j)=dp.at(0).at(j-2);
	//开始执行dp
	for (int i=1;i<s_size+1;++i)
		for (int j=1;j<p_size+1;++j)
		{
			if (p.at(j-1)==s.at(i-1) || p.at(j-1)=='.')
				dp.at(i).at(j)=dp.at(i-1).at(j-1);
			if (p.at(j-1)=='*')
				if (p.at(j-2)==s.at(i-1) || p.at(j-2)=='.')
					dp.at(i).at(j)=dp.at(i-1).at(j)||dp.at(i-1).at(j-2)||dp.at(i).at(j-2);//匹配多个、单个、零个,在匹配单个时有dp.at(i).at(j-1)写法，都对
				else if (p.at(j-2)!=s.at(i-1))
					dp.at(i).at(j)=dp.at(i).at(j-2);//*匹配零个字符
			//因初始化就都是false，不必再加p.at(j)!=s.at(i)不等条件判断
		}
	return dp.at(s_size).at(p_size);
}
};
