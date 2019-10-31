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
