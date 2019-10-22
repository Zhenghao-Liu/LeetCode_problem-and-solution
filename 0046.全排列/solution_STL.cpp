class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
     {
        vector<vector<int>> answer;
        sort(nums.begin(),nums.end());
        do
        {
            answer.push_back(vector<int>(nums));
        }while(next_permutation(nums.begin(),nums.end()));   
	    return answer;
    }
};
