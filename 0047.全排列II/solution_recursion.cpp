class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());//因出现重复的数字，要进行排序不然即使采用nums.at(i)==nums.at(i-1)来剪枝仍会有重复
        vector<vector<int>> answer(permute_m(nums));
        return answer;
    }
    vector<vector<int>> permute_m(vector<int>& nums)
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
		    if (i!=0 && nums.at(i)==nums.at(i-1))//删除重复子串
				continue;
			ans=nums;
		    ans.erase(ans.begin()+i);
		    return_ans=permute_m(ans);
		    int return_ans_size=return_ans.size();
		    for (int j=0;j<return_ans_size;++j)
			{
				answer.push_back(vector<int>({}));
				answer.at(index).push_back(int(nums.at(i)));
				for (int k=0;k<return_ans.at(j).size();++k)
					answer.at(index).push_back(int(return_ans.at(j).at(k)));
				++index;
			}
            ans.clear();
            return_ans.clear();
	    }
	    return answer;
    }
};
