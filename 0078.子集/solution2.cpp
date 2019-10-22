class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        int nums_size=nums.size();
        get_combine(nums,nums_size,nums_size,answer,{});
        return answer;
    }
void get_combine(vector<int> lists,int lists_size,int k,vector<vector<int>>& answer,vector<int> ans)
{
	answer.push_back(ans);
    if (k==0)
	{
		return;
	}
	for (int i=0;i<lists_size;++i)
	{
		ans.push_back(lists.at(0));
		lists.erase(lists.begin());
		get_combine(lists,lists.size(),k-1,answer,ans);
		ans.pop_back();
	}
}
};
