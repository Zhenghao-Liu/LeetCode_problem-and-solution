/*
* 思路是先按左边元素进行排序
* 假设[a,b][c,d]
* 已经按左边元素排过序所以默认a<c
* 若b>=c则代两个有重合部分
* 则需更新为[a,max(b,d)]
* 若b<c则表明无重合所以对下一个区间处理
*/
class Solution {
public:
static bool cmp(const vector<int>& A,const vector<int>& B)
{
	return A.at(0)<B.at(0);
}
vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    int intervals_size=intervals.size();
	if (intervals_size<2)
		return intervals;
	sort(intervals.begin(),intervals.end(),cmp);
	vector<vector<int>> answer;
	answer.push_back(vector<int>(intervals.at(0)));
	int index=0;
	for (int i=1;i<intervals_size;++i)
	{
		if (answer.at(index).at(1)>=intervals.at(i).at(0))
			answer.at(index).at(1)=max(answer.at(index).at(1),intervals.at(i).at(1));
		else
		{
			answer.push_back(vector<int>(intervals.at(i)));
			++index;
		}
	}
	return answer;
}
};
