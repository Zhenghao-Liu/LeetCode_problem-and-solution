//直接双指针记录[i][j]即可
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row=nums.size();
        int column=nums.at(0).size();
        if (row*column!=r*c)
            return nums;
        vector<vector<int>> ans(r,vector<int>(c));
        int x=0,y=0;
        for (vector<int> &i:nums)
            for (int &j:i)
            {
                ans.at(x).at(y)=j;
                ++y;
                if (y==c)
                {
                    ++x;
                    y=0;
                }
            }
        return ans;
    }
};
