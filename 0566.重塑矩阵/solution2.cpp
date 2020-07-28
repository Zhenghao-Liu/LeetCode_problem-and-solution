//可以压缩成单指针因为[i][j]=i*row+j
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row=nums.size();
        int column=nums.at(0).size();
        if (row*column!=r*c)
            return nums;
        vector<vector<int>> ans(r,vector<int>(c));
        int count=0;
        for (vector<int> &i:nums)
            for (int &j:i)
            {
                ans.at(count/c).at(count%c)=j;
                ++count;
            }
        return ans;
    }
};
