class Solution {
public:
bool isInterleave(string s1, string s2, string s3) 
{
    int s1_size=s1.size(),s2_size=s2.size(),s3_size=s3.size();
	if (s1_size+s2_size!=s3_size)
		return false;
	if (s1_size==0)
		return s2==s3;
	else if (s2_size==0)
		return s1==s3;
	vector<vector<bool>> dp(s1_size+1,vector<bool>(s2_size+1,false));
	dp.at(0).at(0)=true;
	for (int i=1;i<=s2_size;++i)
		if (s2.at(i-1)==s3.at(i-1))
			dp.at(0).at(i)=dp.at(0).at(i-1);
	for (int i=1;i<=s1_size;++i)
		if (s1.at(i-1)==s3.at(i-1))
			dp.at(i).at(0)=dp.at(i-1).at(0);
	for (int i=1;i<=s1_size;++i)
		for (int j=1;j<=s2_size;++j)
			if (s1.at(i-1)==s2.at(j-1))
			{
				if (s3.at(i+j-1)==s1.at(i-1))
					dp.at(i).at(j)=dp.at(i-1).at(j) || dp.at(i).at(j-1);
			}
			else if (s3.at(i+j-1)==s1.at(i-1))
				dp.at(i).at(j)=dp.at(i-1).at(j);
			else if (s3.at(i+j-1)==s2.at(j-1))
				dp.at(i).at(j)=dp.at(i).at(j-1);
	return dp.at(s1_size).at(s2_size);
}
};
