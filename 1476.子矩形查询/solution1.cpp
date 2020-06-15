class SubrectangleQueries {
    vector<vector<int>> v;
    int row,column;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        v=rectangle;
        row=v.size();
        column=v.at(0).size();
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i=row1;i<=row2;++i)
            for (int j=col1;j<=col2;++j)
                v.at(i).at(j)=newValue;
    }
    
    int getValue(int row, int col) {
        return v.at(row).at(col);
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
