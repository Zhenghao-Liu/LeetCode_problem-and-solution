class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
     {
	    int nums_size=nums.size();
	    if (nums_size<=1)
		    return {nums};
	    vector<vector<int>> answer;
        vector<int> ans;
        vector<vector<int>> return_ans;
		int index=0;
	    for (int i=0;i<nums_size;++i)
	    {
		    for (int j=0;j<nums_size;++j)
                if (i!=j)
                    ans.push_back(nums.at(j));
		    return_ans=permute(ans);
		    int return_ans_size=return_ans.size();
		    for (int j=0;j<return_ans_size;++j)
			{
				answer.push_back(vector<int>({}));
				answer.at(index).push_back(int(nums.at(i)));
                int return_ans_at_size=return_ans.at(j).size();
				for (int k=0;k<return_ans_at_size;++k)
					answer.at(index).push_back(int(return_ans.at(j).at(k)));
				++index;
			}
            ans.clear();
            return_ans.clear();
	    }
	    return answer;
    }
};
