class Solution {
public:
string minWindow(string s, string t)
{
	int s_size=s.size(),t_size=t.size();
	if (s_size==0 || t_size==0 || t_size>s_size)
		return "";
	unordered_map<char,int> t_number_of_letters;
	for (char i:t)
		++t_number_of_letters[i];
	int left=0,right=-1;
	unordered_map<char,int> window_number_of_letters;
	int judge_stop_increasing_left=0,judge_stop_increasing_right=0;
	int minimum=INT_MAX,low;
	while (right<s_size) 
	{
		while(right<s_size)
		{
			judge_stop_increasing_right=1;
			for (auto i:t_number_of_letters)
				if (i.second>window_number_of_letters[i.first])
				{
					++right;
					judge_stop_increasing_right=0;
					break;
				}
			if(judge_stop_increasing_right==1)
				break;
			else if (right<s_size)
				++window_number_of_letters[s.at(right)];
		}
		while(left<s_size)
		{
			--window_number_of_letters[s.at(left)];
			++left;
			for (auto i:t_number_of_letters)
				if (i.second>window_number_of_letters[i.first])
				{
					judge_stop_increasing_left=1;
					break;
				}
			if (judge_stop_increasing_left==1)
			{
				judge_stop_increasing_left=0;
				break;
			}
		}
		if (right-left+2<minimum && right<s_size)
		{
			low=left-1;
			minimum=right-left+2;
		}
	}
	return (minimum==INT_MAX) ? "" : s.substr(low,minimum);
}
};
