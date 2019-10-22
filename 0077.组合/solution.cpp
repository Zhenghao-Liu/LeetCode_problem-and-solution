//未剪枝但比较好理解
class Solution {
public:
vector<vector<int>> combine(int n, int k) 
{
	vector<vector<int>> answer;
	get_combine(1,n,k,answer,{});
	return answer;
}
void get_combine(int lists,int n,int k,vector<vector<int>>& answer,vector<int> ans)
{
	if (k==0)
	{
		answer.push_back(ans);
		return;
	}
	int loop_times(n);
	for (int i=0;i<loop_times;++i)
	{
		ans.push_back(int(lists++));
		get_combine(lists,--n,k-1,answer,ans);
		ans.pop_back();
	}
}
};
