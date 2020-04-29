class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        ans.reserve(1e5);
        queue<pair<int,int>> helper;
        helper.push({0,0});
        int row=nums.size();
        while (!helper.empty())
        {
            auto [x,y]=helper.front();
            while (!helper.empty() && x==helper.front().first && y==helper.front().second)
                helper.pop();
            ans.push_back(nums[x][y]);
            if (x+1<row && y<nums[x+1].size())
                helper.push({x+1,y});
            if (y+1<nums[x].size())
                helper.push({x,y+1});
        }
        return ans;
    }
};
