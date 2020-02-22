class NumMatrix {
private:
    vector<vector<int>> helper;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size(),column;
        if (row==0)
            return;
        column=matrix.at(0).size();
        helper=vector<vector<int>>(row,vector<int>(column));
        helper.at(0).at(0)=matrix.at(0).at(0);
        for (int i=1;i<column;++i)
            helper.at(0).at(i)=matrix.at(0).at(i)+helper.at(0).at(i-1);
        for (int i=1;i<row;++i)
            helper.at(i).at(0)=matrix.at(i).at(0)+helper.at(i-1).at(0);
        for (int i=1;i<row;++i)
            for (int j=1;j<column;++j)
                helper.at(i).at(j)=matrix.at(i).at(j)+helper.at(i).at(j-1)+helper.at(i-1).at(j)-helper.at(i-1).at(j-1);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int left=col1>0 ? helper.at(row2).at(col1-1) : 0;
        int up=row1>0 ? up=helper.at(row1-1).at(col2) : 0;
        int overlap=row1>0 && col1>0 ? overlap=helper.at(row1-1).at(col1-1) : 0;
        return helper.at(row2).at(col2)-left-up+overlap;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
