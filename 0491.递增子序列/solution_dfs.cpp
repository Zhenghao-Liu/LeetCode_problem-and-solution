class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        ans.clear();
        vector<int> cur;
        dfs(nums,0,nums.size(),cur);
        return ans;
    }
    void dfs(vector<int> &nums,int start,int nums_size,vector<int> &cur)
    {
        if (cur.size()>=2)
            ans.push_back(cur);
        unordered_set<int> helper;
        for (int i=start;i<nums_size;++i)
        {
            if (helper.find(nums.at(i))!=helper.end())
                continue;
            if (cur.empty() || nums.at(i)>=cur.back())
            {
                helper.insert(nums.at(i));
                cur.push_back(nums.at(i));
                dfs(nums,i+1,nums_size,cur);
                cur.pop_back();
            }
        }
    }
};
