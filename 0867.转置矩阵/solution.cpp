class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix.at(0).size();
        vector<vector<int>> ans(col,vector<int>(row));
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                ans.at(j).at(i)=matrix.at(i).at(j);
            }
        }
        return ans;
    }
};
