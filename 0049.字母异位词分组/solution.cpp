class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	int strs_size=strs.size();
	if (strs_size==0)
		return {{}};
	vector<vector<string>> answer;
	vector<string> sorted_strs;
	int answer_size=0,judge;
	string ans_str;
	for (int i=0;i<strs_size;++i)
	{
		judge=-1;
		ans_str=strs.at(i);
		sort(ans_str.begin(),ans_str.end());
		for (int j=0;j<answer_size;++j)
			if (ans_str.compare(sorted_strs.at(j))==0)
				judge=j;
		if (judge!=-1)
			answer.at(judge).push_back(string(strs.at(i)));
		else
		{
			sorted_strs.push_back(string(ans_str));
			answer.push_back(vector<string>({}));
			++answer_size;
			answer.at(answer_size-1).push_back(string(strs.at(i)));
		}
	}
	return answer;
}
};
