//迷之剪枝。。。
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
	if (ans.size()==k)
	{
		answer.push_back(ans);
		return;
	}
	//诡异的剪枝
	for (int i=lists;i<n-k+ans.size()+2;)
	{
		ans.push_back(int(i));
		get_combine(++i,n,k,answer,ans);
		ans.pop_back();
	}
}
};
