class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int nums_size=nums.size();
        vector<bool> visited(nums_size,false);
        vector<vector<int>> ans;
        vector<int> helper;
        dfs(nums,nums_size,ans,visited,helper);
        return ans;
    }
    void dfs(vector<int> &nums,const int &nums_size,vector<vector<int>> &ans,vector<bool> &visited,vector<int> &helper)
    {
        if (helper.size()==nums_size)
        {
            ans.push_back(helper);
            return;
        }
        for (int i=0;i<nums_size;++i)
            if (!visited.at(i))
            {
                helper.push_back(nums.at(i));
                visited.at(i)=true;
                dfs(nums,nums_size,ans,visited,helper);
                helper.pop_back();
                visited.at(i)=false;
            }
    }
};
