//取每行每列的和的最小值，但是同时更新每行每列剩下的和
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row=rowSum.size();
        int column=colSum.size();
        vector<vector<int>> ans(row,vector<int>(column));
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
            {
                ans.at(i).at(j)=min(rowSum.at(i),colSum.at(j));
                rowSum.at(i)-=ans.at(i).at(j);
                colSum.at(j)-=ans.at(i).at(j);
            }
        return ans;
        
    }
};
