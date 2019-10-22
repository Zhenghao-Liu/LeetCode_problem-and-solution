vector<vector<int>> answer;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        answer.clear();
        sort(candidates.begin(),candidates.end());
	    int candidates_size=candidates.size();
	    find_substr(candidates,target,candidates_size,{},0);
        return answer;
    }
    void find_substr(vector<int> &candidates,const int& target,const int & candidates_size,vector<int> ans,const int& begin_size)
    {
	    int sum;
	    for (int i=begin_size;i<candidates_size;++i)
	    {
		    if (i!=begin_size && candidates.at(i)==candidates.at(i-1))
			    continue;
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
			    find_substr(candidates,target,candidates_size,ans,i+1);
		    ans.pop_back();
	    }
	    return;
    } 
};
