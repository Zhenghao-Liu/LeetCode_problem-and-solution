vector<vector<int>> answer;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int candidates_size=candidates.size();
        answer.clear();
	    find_substr(candidates,target,candidates_size,{},0);
        return answer;
    }
    void find_substr(vector<int> &candidates,const int& target,const int & candidates_size,vector<int> ans,const int& begin_size)
{
	int sum;
	for (int i=begin_size;i<candidates_size;++i)
	{
		sum=0;
		ans.push_back(candidates.at(i));
		for (int j=0;j<ans.size();++j)
			sum=sum+ans.at(j);
		if (sum==target)
		{
			answer.push_back(vector<int>(ans));
			return;
		}
		else if (sum<target)
			find_substr(candidates,target,candidates_size,ans,i);
		ans.pop_back();
	}
	return;
} 
};
