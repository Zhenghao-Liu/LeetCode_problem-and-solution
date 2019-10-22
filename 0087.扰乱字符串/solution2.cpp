class Solution {
public:
bool isScramble(string s1, string s2) 
{
    if (s1==s2)
		return true;
	int s1_size=s1.size(),s2_size=s2.size(),s1_ascii=0,s2_ascii=0;
	for (int i=0;i<s1_size;++i)
		s1_ascii=s1_ascii+int(s1.at(i));
	for (int i=0;i<s2_size;++i)
		s2_ascii=s2_ascii+int(s2.at(i));
	if (s1_size!=s2_size || s1_ascii!=s2_ascii)
		return false;
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
