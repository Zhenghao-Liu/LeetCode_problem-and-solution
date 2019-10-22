class Solution {
public:
bool isScramble(string s1, string s2) 
{
    if (s1==s2)
		return true;
	int s1_size=s1.size(),s2_size=s2.size();
	if (s1_size!=s2_size)
		return false;
    {
        string ss1(s1),ss2(s2);
        sort(ss1.begin(),ss1.end());
        sort(ss2.begin(),ss2.end());
        if (ss1!=ss2)
            return false;
    }
	for (int i=1;i<s1_size;++i)
	{
		if (isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,s1_size-i),s2.substr(i,s2_size-i)))
			return true;
		if (isScramble(s1.substr(0,i),s2.substr(s2_size-i,i)) && isScramble(s1.substr(i,s1_size-i),s2.substr(0,s2_size-i)))
			return true;
	}
	return false;
}
};
