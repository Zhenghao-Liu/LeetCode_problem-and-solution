class Solution {
public:
vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
	vector<vector<int>> answer;
	int nums_size=nums.size();
	sort(nums.begin(),nums.end());
	answer.push_back(vector<int>({}));
	for (int i=1;i<nums_size;++i)
		get_combine(nums,nums_size,i,answer,{});
	answer.push_back(vector<int>(nums));
	return answer;
}
void get_combine(vector<int> lists,int lists_size,int k,vector<vector<int>>& answer,vector<int> ans)
{
	if (k==0)
	{
        answer.push_back(ans);
		return;
	}
    int temporary;
	for (int i=0;i<lists_size;++i)
	{
		if (i!=0 && lists.at(0)==temporary)
        {
			lists.erase(lists.begin());
			continue;
		}
        ans.push_back(lists.at(0));
        temporary=lists.at(0);
		lists.erase(lists.begin());
		get_combine(lists,lists.size(),k-1,answer,ans);
		ans.pop_back();
	}
}
};
