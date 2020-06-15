//存历史记录
class SubrectangleQueries {
    vector<vector<int>> v;
    vector<vector<int>> past;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        v=rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        past.push_back({row1,col1,row2,col2,newValue});
    }
    
    int getValue(int row, int col) {
        for (int i=past.size()-1;i>=0;--i)
            if (row>=past[i][0] && row<=past[i][2] && col>=past[i][1] && col<=past[i][3])
                return past[i][4];
        return v[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
