/*
* 评论区给的神奇算法
* 用质数表示26个字母，把字符串的各个字母相乘，这样可保证字母异位词的乘积必定是相等的。
* 其余步骤就是用map存储
*/
class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	int strs_size=strs.size();
	if (strs_size==0)
		return {{}};
	vector<double> key({2,3,5,7,11,13,
						17,19,23,29,31,37,
						41,43,47,53,59,61,
						67,71,73,79,83,89,
						97,101});
	unordered_map<double,vector<string>> map_strs;
	double product;
	for (string single_str:strs)
	{
		product=1.0;
		for (char single_letter:single_str)
			product=product*key.at(int(single_letter-'a'));
		map_strs[product].push_back(single_str);
	}
	vector<vector<string>> answer;
	for (auto i:map_strs)
		answer.push_back(i.second);
	return answer;
}
};
